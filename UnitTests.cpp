#include "Header.h"

#define CATCH_CONFIG_MAIN
#include"catch.hpp"


TEST_CASE("Galutinio vidurkio skaiciavimas") {

	REQUIRE(GalutinisVidurkis(7.7, 8) == 7.88);
	REQUIRE(GalutinisVidurkis(2, 4) == 3.2);
	REQUIRE(GalutinisVidurkis(8, 10) == 9.2);
	REQUIRE(GalutinisVidurkis(5, 6) == 5.6);
	REQUIRE(GalutinisVidurkis(7.2, 4) == 5.28);
}

TEST_CASE("Praslydusio studento tikrinimas") {

	REQUIRE(Praslydes(7) == true);
	REQUIRE(Praslydes(5) == true);
	REQUIRE(Praslydes(1) == false);

}