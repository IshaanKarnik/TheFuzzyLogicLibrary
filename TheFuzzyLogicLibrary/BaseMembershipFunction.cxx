#include "BaseMembershipFunction.hxx"
#include "BaseMembershipFunction.hxx"

namespace tfll
{

	double BaseMembershipFunction::get_input(void) const
	{
		return this->input;
	}

	std::vector<double> BaseMembershipFunction::get_membership_function_parameters(void) const
	{
		return this->membership_function_parameters;
	}

	double BaseMembershipFunction::get_output(void) const
	{
		return this->output;
	}

	double BaseMembershipFunction::get_membership_value(void) const
	{
		return this->fuzzy_membership_value;
	}

}
