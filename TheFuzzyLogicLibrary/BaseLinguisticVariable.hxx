#pragma once

#include <vector>
#include <utility>
#include "BaseMembershipFunction.hxx"

namespace tfll
{

	/*typedef struct LinguisticVariable
	{
		double start;	//start -> Where the range of Linguistic Variable starts
		double end;		//end   -> Where the range of Linguistic Variable ends
	}LinguisticVariable_t;*/

	/// @brief Enumaration that defines type of Linguistic Variable. Is it either input variable or output variable
	typedef enum class LinguisticVariableType : std::uint8_t
	{
		input = 0,
		output
	}linguistic_variable_type_t;

	class BaseLinguisticVariable
	{
	public:
		BaseLinguisticVariable(double start = 0, double end = 1) : range(std::make_pair(start, end))
		{}

		~BaseLinguisticVariable()
		{}

		/// @brief Getter tat returns start value of the linguistic variable
		/// @param
		/// @Exception No-throw guarantee: this function never throws exceptions
		/// @return The start value of the linguistic variable
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		inline double get_start(void) const
		{
			return std::get<0>(this->range);
		}

		/// @brief Getter tat returns end value of the linguistic variable
		/// @param
		/// @Exception No-throw guarantee: this function never throws exceptions
		/// @return The end value of the linguistic variable
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		inline double get_end(void) const
		{
			return std::get<1>(this->range);
		}

		/// @brief	The function is used to set the range of the linguistic variable
		/// @param	start Starting Value for the linguistic variable
		/// @param	end Ending Value for the linguistic variable
		/// @Exception No-throw guarantee: this function never throws exceptions
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		inline void set_range(double start, double end)
		{
			std::get<0>(this->range) = start;
			std::get<1>(this->range) = end;
		}

		/// @brief Adds a membership function to the linguistic variable
		/// @param membership_function An object of BaseMembershipFunction
		/// @Exception	If an exception is thrown (which can be due to Allocator::allocate() or 
		///				element copy/move constructor/assignment), this function has no effect 
		///				(strong exception guarantee). 
		/// @author Ishaan Karnik
		/// @Date	02-09-2023
		void add_membership_function(BaseMembershipFunction&& membership_function);
	protected:
		/// @brief Stores the range of the linguistic variable.
		/// first -> start  -> Starting Value for the linguistic variable
		/// second -> end   -> Ending Value for the linguistic variable
		std::pair<double, double>			range; 
		// LinguisticVariable_t				range;
		
		/// @brief Stores individual membership function.
		/// BaseMembershipFunction objects are stored in this vector which typecasted to actual implemnation 
		/// at runtime.
		std::vector<BaseMembershipFunction> membership_function;
	};
}