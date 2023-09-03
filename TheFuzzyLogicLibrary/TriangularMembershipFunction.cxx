#include "TriangularMembershipFunction.hxx"

#include <algorithm>


namespace tfll
{
	void TriangularMembershipFunction::fuzzifier(void)
	{
		//trimf(x;a,b,c)=max(min(x−a/b−a,c−x/c−b),0)
		this->fuzzy_membership_value = std::max(
			std::min(
				(this->input - this->get_a()) / (this->get_b() - this->get_a()), //x−a/b−a
				(this->get_c() - this->input) / (this->get_c() - this->get_b())  //c−x/c−b
			),
			0.0 //0
		);
	}

	void TriangularMembershipFunction::set_membership_function_parameters(double a, double b, double c)
	{
		this->membership_function_parameters.clear();
		this->membership_function_parameters.push_back(a);
		this->membership_function_parameters.push_back(b);
		this->membership_function_parameters.push_back(c);
		if (this->validate_membership_function_parameters() == false)
		{
			throw InvaidMembershipFunctionParameter();
		}
	}

	void TriangularMembershipFunction::set_membership_function_parameters(std::vector<double> membership_function_parameters)
	{
		this->membership_function_parameters.clear();
		this->membership_function_parameters = membership_function_parameters;
		if (this->validate_membership_function_parameters() == false)
		{
			throw InvaidMembershipFunctionParameter();
		}
	}

	bool TriangularMembershipFunction::validate_membership_function_parameters(void)
	{
		//TODO
		return false;
	}

	double TriangularMembershipFunction::get_a(void) const
	{
		return this->membership_function_parameters.at(0);
	}

	double TriangularMembershipFunction::get_b(void) const
	{
		return this->membership_function_parameters.at(1);;
	}

	double TriangularMembershipFunction::get_c(void) const
	{
		return this->membership_function_parameters.at(2);
	}
}