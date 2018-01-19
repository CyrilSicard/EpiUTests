#include "tests-common.hpp"


#if	TEST_EXO >= 2 && TEST_EXO <= 3
#include "Cesar.hpp"
#include "OneTime.hpp"

void	testAve(std::stringstream &out)
{
	Cesar	c;

	c.reset();

	c.encryptChar('H');
	std::cout << std::endl;

	cr_assert_line(out, "K", "Caesar code 1st char");

	c.encryptChar('H');
	std::cout << std::endl;

	cr_assert_line(out, "L", "Caesar code 2nd char");

	c.encryptChar('h');
	std::cout << std::endl;

	cr_assert_line(out, "m", "Caesar code 3rd char");

	c.decryptChar('K');
	std::cout << std::endl;

	cr_assert_line(out, "H", "Caesar decoding 1st char");

	c.decryptChar('l');
	std::cout << std::endl;

	cr_assert_line(out, "h", "Caesar decoding 2nd char");

	c.reset();

	c.encryptChar('H');
	c.decryptChar('K');
	std::cout << std::endl;

	cr_assert_line(out, "KH", "Reset");

	c.reset();

	c.encryptChar('Z');
	c.encryptChar('z');
	c.decryptChar('A');
	c.decryptChar('a');
	std::cout << std::endl;

	cr_assert_line(out, "CdXw", "End of alphabet");

	for (int i = 0; i < 30; ++i) {
		c.encryptChar('Z');
		c.encryptChar('z');
		c.decryptChar('a');
		c.decryptChar('A');
	}
	std::cout << std::endl;

	cr_assert_line(out, "EfvUGhtSIjrQKlpOMnnMOplKQrjISthGUvfEWxdCYzbAAbzYCdxWEfvUGhtSIjrQKlpOMnnMOplKQrjISthGUvfEWxdCYzbAAbzYCdxWEfvUGhtSIjrQKlpO", "End of char size");
	//cr_assert_line(out, "EfuTGhsRIjqPKloNMnmLOpkJQriHStgFUveDWxcBYzaZAbyXCdwVEfuTGhsRIjqPKloNMnmLOpkJQriHStgFUveDWxcBYzaZAbyXCdwVEfuTGhsRIjqPKloN", "End of char size");
	OneTime	ot("defgHIJklMnOPqRstuvWXyzaBc");

	ot.reset();

	ot.encryptChar('H');
	std::cout << std::endl;

	cr_assert_line(out, "K", "OneTime code 1st char");

	ot.encryptChar('H');
	std::cout << std::endl;

	cr_assert_line(out, "L", "OneTime code 2nd char");

	ot.encryptChar('h');
	std::cout << std::endl;

	cr_assert_line(out, "m", "OneTime code 3rd char");

	ot.decryptChar('K');
	std::cout << std::endl;

	cr_assert_line(out, "H", "OneTime decoding 1st char");

	ot.decryptChar('l');
	std::cout << std::endl;

	cr_assert_line(out, "h", "OneTime decoding 2nd char");

	ot.reset();

	ot.encryptChar('H');
	ot.decryptChar('K');
	std::cout << std::endl;

	cr_assert_line(out, "KH", "OneTime Reset");

	ot.reset();

	ot.encryptChar('Z');
	ot.encryptChar('z');
	ot.decryptChar('A');
	ot.decryptChar('a');
	std::cout << std::endl;

	cr_assert_line(out, "CdXw", "OneTime End of alphabet");

	for (int i = 0; i < 30; ++i) {
		ot.encryptChar('Z');
		ot.encryptChar('z');
		ot.decryptChar('a');
		ot.decryptChar('A');
	}
	std::cout << std::endl;

	cr_assert_line(out, "EfvUGhtSIjrQKlpOMnnMOplKQrjISthGUvfEWxdCYzbAAbzYCdxWEfvUGhtSIjrQKlpOMnnMOplKQrjISthGUvfEWxdCYzbAAbzYCdxWEfvUGhtSIjrQKlpO", "OneTime End of char size");
	//cr_assert_line(out, "EfuTGhsRIjqPKloNMnmLOpkJQriHStgFUveDWxcBYzaZAbyXCdwVEfuTGhsRIjqPKloNMnmLOpkJQriHStgFUveDWxcBYzaZAbyXCdwVEfuTGhsRIjqPKloN", "OneTime End of char size");
	OneTime	ot2("YoucIdiot");

	ot2.encryptChar('Y');
	ot2.encryptChar('o');
	ot2.encryptChar('u');
	ot2.encryptChar(' ');
	ot2.encryptChar('I');
	ot2.encryptChar('d');
	ot2.encryptChar('i');
	ot2.encryptChar('o');
	ot2.encryptChar('t');
	ot2.encryptChar('!');
	std::cout << std::endl;

	cr_assert_line(out, "Wco Qgqcm!", "idiot test");
	OneTime	ot3("fep");

	ot3.encryptChar('A');
	ot3.encryptChar('a');
	ot3.encryptChar('a');
	ot3.encryptChar('a');
	ot3.encryptChar('a');
	std::cout << std::endl;

	cr_assert_line(out, "Fepfe", "Fepaça test");
}
#endif