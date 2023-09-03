#pragma once
#include <vector>
#include <string>
#include <stdexcept>

namespace tfll
{
	class InvaidMembershipFunctionParameter : std::exception
	{
	public:
		const char* what() const override
		{
			return message.c_str();
		}
	private:
		inline static const std::string message{ "Invaid Membership Function Parameter" };
	};

	/// @brief Enumaration that defines possible supported membership functions
	typedef enum class MembershipFunctionType : std::uint8_t
	{
		none = 0,
		triangular,
		trapezoidal,
		s_shaped,
		z_shaped,
		linear_s_shaped,
		linear_z_shaped,
		gaussian,
		pi_shaped,
		generalized_bell
		//TODO Additional Functions to be added
	}membership_function_type_t;

	class BaseMembershipFunction
	{
	public:
		BaseMembershipFunction(membership_function_type_t membership_funnction_type) : 
			membership_funnction_type(membership_funnction_type)
		{
		}

		~BaseMembershipFunction()
		{
		}

		/// @brief This function computes fuzzy membership values
		/// @param  
		virtual void fuzzifier(void)		= 0;

		/// @brief Sets the Membership function parameters
		/// @param membership_function_parameters Membership function parameters, specified as the vector
		virtual void set_membership_function_parameters(std::vector<double> membership_function_parameters)	= 0;

		//TODO
		//virtual void set_membership_papameters(void)		= 0;

		/// @brief Checks if the membership_function_parameters set by set_membership_function_parameters are valid
		/// @param  
		/// @return True if membership function parameters are valid else false
		virtual bool validate_membership_function_parameters(void) = 0;

		/// @brief Generate a defuzzified output value for membership function
		/// @param  
		//virtual void defuzzifier(void)		= 0;

		/// @brief Gets input value
		/// @param  
		/// @return Returns input value
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_input(void) const;

		/// @brief Gets Membership Function Parameters value
		/// @param  
		/// @return Returns the Membership Function Parameters value
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		std::vector<double> get_membership_function_parameters(void) const;

		/// @brief Gets output variable value
		/// @param  
		/// @return Returns the output variable
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_output(void) const;

		/// @brief Gets fuzzy membership value
		/// @param  
		/// @return Returns the fuzzy membership variable
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		double get_membership_value(void) const;
	protected:
		MembershipFunctionType				membership_funnction_type;
		/// @brief input value
		double								input{ 0.0 };
		/// @brief Membership function parameters
		std::vector<double>					membership_function_parameters;
		/// @brief output value
		double								output{ 0.0 };
		/// @brief Fuzzy Membership Value
		double								fuzzy_membership_value{ 0.0 };
	};

}