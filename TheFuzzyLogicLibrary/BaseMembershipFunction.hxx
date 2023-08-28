#pragma once
#include <vector>
namespace tfll
{

	enum class MembershipFunctionType : std::uint8_t
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
	};

	class BaseMembershipFunction
	{
	public:
		BaseMembershipFunction()
		{
		}

		~BaseMembershipFunction()
		{
		}
	protected:
		std::vector<double> break_points; //Anchor points-Break points in the membership function
	private:

	};

}