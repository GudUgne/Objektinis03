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

TEST_CASE("Studentu skolos pagal suskaiciuota galutini naudojant vidurki") {

	Studentas S1, S2, S3;
	S1.setFinalAve(8);
	S2.setFinalAve(4);
	S3.setFinalAve(9);

	REQUIRE(Skola1(S1) == true);
	REQUIRE(Skola1(S2) == false);
	REQUIRE(Skola1(S3) == true);
}
