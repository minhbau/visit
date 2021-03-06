/*****************************************************************************
*
* Copyright (c) 2010, University of New Hampshire Computer Science Department
* All rights reserved.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  File:        avtMultiresControlFilter.C                                  //
//  Programmer:  Andrew Foulks <rafoulks@cs.unh.edu>                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include <iterator>
#include <list>

#include <avtMultiresControlFilter.h>

#include <avtDomainNesting.h>
#include <avtMetaData.h>
#include <avtResolutionSelection.h>
#include <avtStructuredDomainNesting.h>
#include <DebugStream.h>

avtMultiresControlFilter::avtMultiresControlFilter()
{
}

avtFilter* avtMultiresControlFilter::Create()
{
    return new avtMultiresControlFilter();
}

void avtMultiresControlFilter::SetAtts(const AttributeGroup *a)
{
    atts = *(const MultiresControlAttributes*)a;
}

bool avtMultiresControlFilter::Equivalent(const AttributeGroup *a)
{
    return (atts == *(MultiresControlAttributes*)a);
}

// ****************************************************************************
//   Modifications:
//     Eric Brugger, Wed Jul 30 19:50:54 PDT 2014
//     Modified the class to work with avtDataRepresentation.
//
// ****************************************************************************

avtDataRepresentation * 
avtMultiresControlFilter::ExecuteData(avtDataRepresentation *in_dr)
{
    size_t lods =
      GetTypedInput()->GetInfo().GetAttributes().GetLevelsOfDetail();
    debug3 << "Setting max resolution to " << lods << "\n";
    atts.SetMaxResolution((int)lods);
    return in_dr;
}

avtContract_p avtMultiresControlFilter::ModifyContract(avtContract_p contract)
{
    //  This method sends messages via 'contract'.  See method 
    //  avtMultiresDataFileFormat::RegisterDataSelections to see
    //  the 'listener' of the messages sent from here.  This method
    //  sends messages to the database plugin to change the
    //  resolution.

    avtResolutionSelection* res = new avtResolutionSelection;

    res->setResolution(atts.GetResolution());
    contract->GetDataRequest()->AddDataSelection(res);

    // Attempt to lookup the domain level information.  If it gives this
    // information, we can turn off domains in the restriction and avoid
    // reading/processing them at all.  Not all DBs supply this though, so we
    // need to bail if we get some nulls.
    avtDomainNesting* dni = GetMetaData()->GetDomainNesting();
    if(dni == NULL)
        return contract;

    avtStructuredDomainNesting* sdn =
      dynamic_cast<avtStructuredDomainNesting*>(dni);
    if(sdn == NULL)
        return contract;

    std::vector<int> domain_list;
    std::back_insert_iterator<std::vector<int> > doms(domain_list);
    int max_domain = (int)sdn->GetNumberOfDomains();
    for(int dom=0; dom < max_domain; ++dom)
    {
        int level = sdn->GetDomainLevel(dom);
        if(level <= atts.GetResolution())
        {
            *doms = dom;
        }
    }

    contract->GetDataRequest()->GetRestriction()->RestrictDomains(domain_list);

    return contract;
}

avtMultiresControlFilter::~avtMultiresControlFilter()
{
}
