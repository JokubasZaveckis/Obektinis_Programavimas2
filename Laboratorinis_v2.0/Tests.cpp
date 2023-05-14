#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Funkcijos.h"

TEST_CASE("Studentas constructor with valid input works correctly") {
    std::vector<int> pazymiai = { 5, 8, 7 };
    Studentas s("Vardas", "Pavarde", pazymiai, 7);

    REQUIRE(s.getVardas() == "Vardas");
    REQUIRE(s.getPavarde() == "Pavarde");
    REQUIRE(s.get_vidurkis() != 0);
    REQUIRE(s.get_mediana() != 0);
}

TEST_CASE("Vidurkis calculates average correctly", "[Studentas]") {
    std::vector<int> pazymiai = { 5, 8, 7 };
    Studentas s("Vardas", "Pavarde", pazymiai, 7);

    s.Vidurkis(pazymiai, 7);
    REQUIRE(s.get_vidurkis() != 0 );
}