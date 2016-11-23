#include "stdafx.h"
#include "../Lab3/Car.h"
#include <boost/function.hpp>

struct CCarFixture
{
	CCar car;
};

void ExpectFailure(CCar car, const std::function<bool(CCar & car)> & operation)
{
	CCar clone(car);
	BOOST_CHECK(!operation(clone));
	BOOST_CHECK_EQUAL(clone.IsEngineOn(), car.IsEngineOn());
	BOOST_CHECK(clone.GetCurrentGear() == car.GetCurrentGear());
	BOOST_CHECK_EQUAL(clone.GetCurrentSpeed(), car.GetCurrentSpeed());
}

BOOST_FIXTURE_TEST_SUITE(Car, CCarFixture)
	BOOST_AUTO_TEST_CASE(turned_off_by_default)
	{
		BOOST_CHECK(!car.IsEngineOn());
	}

	BOOST_AUTO_TEST_CASE(cant_set_gear_when_turned_off)
	{
		ExpectFailure(car, [](auto & car)
		{
			return car.SetGear(6);
		});
		BOOST_CHECK_EQUAL(car.GetCurrentGear(), 0);
	}

	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		car.TurnEngineOn();
		BOOST_CHECK(car.IsEngineOn());
	}
	BOOST_AUTO_TEST_CASE(on_create_speed_is_0)
	{
		BOOST_CHECK(car.GetCurrentSpeed() == 0);
	}
	BOOST_AUTO_TEST_CASE(neutral_gear_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetCurrentGear(), 0);
	}

	struct when_turned_on_ : CCarFixture
	{
		when_turned_on_()
		{
			car.TurnEngineOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)
		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			BOOST_CHECK(car.TurnEngineOff());
		}
		BOOST_AUTO_TEST_CASE(on_speed_is_0)
		{
			BOOST_CHECK_EQUAL(car.GetCurrentSpeed(), 0);
		}
		BOOST_AUTO_TEST_CASE(can_set_a_reverse_gear)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK_EQUAL(car.GetCurrentGear(), -1);
		}
		BOOST_AUTO_TEST_CASE(when_the_speed_is_not_zero_the_engine_doest_off)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(20));
			ExpectFailure(car, [](auto & car)
			{
				return car.TurnEngineOff();
			});
		}

		BOOST_AUTO_TEST_CASE(engine_can_only_be_off_in_the_neutral_position_at_zero_speed)
		{
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.TurnEngineOff());
		}

		BOOST_AUTO_TEST_CASE(it_is_impossible_to_accelerate_in_neutral)
		{
			BOOST_CHECK(car.GetCurrentGear() == 0);
			ExpectFailure(car, [](auto & car)
			{
				return car.SetSpeed(10);
			});
		}

		struct when_reverse_gear_set_ : when_turned_on_
		{
			when_reverse_gear_set_()
			{
				car.SetGear(-1);
				car.SetSpeed(15);
			}
		};

		BOOST_FIXTURE_TEST_SUITE(when_reverse_gear_set, when_reverse_gear_set_)
			BOOST_AUTO_TEST_CASE(can_set_speed_ranged_from_0_to_20)
			{
				car.SetSpeed(20);
				BOOST_CHECK_EQUAL(car.GetCurrentSpeed(), 20);
			}

			BOOST_AUTO_TEST_CASE(can_set_the_neutral_gear)
			{
				BOOST_CHECK(car.SetGear(0));
				BOOST_CHECK_EQUAL(car.GetCurrentGear(), 0);
			}

			BOOST_AUTO_TEST_CASE(can_not_set_the_first_gear)
			{
				ExpectFailure(car, [](auto & car)
				{
					return car.SetGear(1);
				});
				BOOST_CHECK_EQUAL(car.GetCurrentGear(), -1);
			}

			BOOST_AUTO_TEST_CASE(can_not_switch_to_the_first_speed_is_when_gear_equal_to_reverse)
			{
				ExpectFailure(car, [](auto & car)
				{
					return car.SetGear(1);
				});
				BOOST_CHECK_EQUAL(car.GetCurrentGear(), -1);
			}

			BOOST_AUTO_TEST_CASE(can_switch_to_the_first_speed_is_when_gear_equal_to_neutral)
			{
				BOOST_CHECK(car.SetGear(0));
				BOOST_CHECK(car.SetSpeed(0));
				BOOST_CHECK(car.SetGear(1));
				BOOST_CHECK_EQUAL(car.GetCurrentGear(), 1);
			}

			struct when_neutral_gear_set_ : when_turned_on_
			{
				when_neutral_gear_set_()
				{
					car.SetGear(1);
					car.SetSpeed(10);
					car.SetGear(0);
				}
			};
			BOOST_FIXTURE_TEST_SUITE(when_neutral_gear_set, when_neutral_gear_set_)
				BOOST_AUTO_TEST_CASE(car_can_not_accelerated_speed)
				{
					ExpectFailure(car, [](auto & car)
					{
						return car.SetSpeed(20);
					});
					BOOST_CHECK_EQUAL(car.GetCurrentSpeed(), 10);
				}
				BOOST_AUTO_TEST_CASE(car_can_reduce_speed)
				{
					BOOST_CHECK(car.SetSpeed(5));
					BOOST_CHECK_EQUAL(car.GetCurrentSpeed(), 5);
				}

				BOOST_AUTO_TEST_CASE(car_cant_increase_speed)
				{
					BOOST_CHECK(car.SetSpeed(5));
					BOOST_CHECK_EQUAL(car.GetCurrentSpeed(), 5);
				}

				BOOST_AUTO_TEST_CASE(while_moving_forward_can_not_be_turned_reverse_gear) 
				{
					ExpectFailure(car, [](auto & car)
					{
						return car.SetGear(-1);
					});
				}
			BOOST_AUTO_TEST_SUITE_END()

			struct when_the_car_is_moving_ : when_turned_on_
			{
				when_the_car_is_moving_()
				{
					car.SetGear(1);
					car.SetSpeed(10);
				}
			};
			BOOST_FIXTURE_TEST_SUITE(when_the_car_is_moving, when_the_car_is_moving_)
				BOOST_AUTO_TEST_CASE(car_cant_drive_at_a_speed_which_ist_suitable_for_the_current_gear)
				{
					ExpectFailure(car, [](auto & car)
					{
						return car.SetSpeed(40);
					});
				}

				BOOST_AUTO_TEST_CASE(car_cant_change_the_gear_ist_available_during_motion_at_the_current_speed)
				{
					ExpectFailure(car, [](auto & car)
					{
						return car.SetGear(2);
					});
				}

				BOOST_AUTO_TEST_CASE(while_moving_forward_can_not_be_turned_reverse_gear) 
				{
					ExpectFailure(car, [](auto & car)
					{
						return car.SetGear(-1);
					});
				}
			BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()