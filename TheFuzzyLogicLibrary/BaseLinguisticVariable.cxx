#include "BaseLinguisticVariable.hxx"

namespace tfll
{
    void BaseLinguisticVariable::add_membership_function(BaseMembershipFunction&& membership_function)
    {
        this->membership_function.push_back(membership_function);
    }
}