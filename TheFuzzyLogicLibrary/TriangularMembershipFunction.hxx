#pragma once

#include "BaseMembershipFunction.hxx"

namespace tfll
{
	class TriangularMembershipFunction : public BaseMembershipFunction
	{
	public:
		TriangularMembershipFunction() : BaseMembershipFunction(MembershipFunctionType::triangular)
		{}

		~TriangularMembershipFunction()
		{}
		/// @brief This function computes fuzzy membership values using a triangular membership function
		/// $$ y = \frac{x+1}{x+2} $$
		/// Exception std::out_of_range If values of a, b and c are not set
		/// @param  
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		/// @todo	Add equations for doxygen documenation
		void fuzzifier(void) override;

		/// @brief Sets the Membership function parameters
		/// Exception If an exception is thrown (which can be due to Allocator::allocate() or element copy/move constructor/assignment), this function has no effect (strong exception guarantee)
		/// @param a Parameters a define the left-feet of the membership function
		/// @param b Parameters b defines the peak of the membership function
		/// @param c Parameters c define the right-feet of the membership function
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		void set_membership_function_parameters(double a, double b, double c);// override;

		/// @brief Sets the Membership function parameters
		/// Exception If an exception is thrown (which can be due to Allocator::allocate() or element copy/move constructor/assignment), this function has no effect (strong exception guarantee)
		/// @param membership_function_parameters Membership function parameters, specified as the vector [a b c]. Parameters a and c define the left-feet and right-feet of the membership function, and b defines the peak of the membership function		
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		void set_membership_function_parameters(std::vector<double> membership_function_parameters) override;

		/// @brief Checks if the membership_function_parameters set by set_membership_function_parameters are valid
		/// @param  
		/// @return True if membership function parameters are valid else false
		bool validate_membership_function_parameters(void) override;

		/// @brief Gets fuzzy parameter value  'a'
		/// Exception std::out_of_range if value of vector is not size 1 
		/// @param  
		/// @return Returns the fuzzy parameter value  'a'
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_a(void) const;

		/// @brief Gets fuzzy parameter value  'b'
		/// Exception std::out_of_range if value of vector is not size 2
		/// @param  
		/// @return Returns the fuzzy parameter value  'b'
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_b(void) const;

		/// @brief Gets fuzzy parameter value  'c'
		/// Exception std::out_of_range if value of vector is not size 3
		/// @param  
		/// @return Returns the fuzzy parameter value  'c'
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_c(void) const;
	private:

	};
}