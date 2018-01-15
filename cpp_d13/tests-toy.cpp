#include "Picture.hpp"
#include "Toy.hpp"

#include "tests-common.hpp"


template<typename T>
void	cr_assert_eq(T one, T two, const std::string &msg)
{
	*my_cout << "\033[90m";
	if (one == two)
		*my_cout << msg << ": \033[32mPassed";
	else
		*my_cout << msg << ": \033[31mFailed";
	*my_cout << "\033[0m" << std::endl;
}

const std::string CONST_BUZZ_ASCII = "      __...-=--=-=--=---=---=-..__\n\
 .,--~                            ~~--.._\n\
'                .,;;!!!!!!!;;,,,.       `--._\n\
             ;;!!'`.,,,,.````````'''>>;;,     `-._\n\
          ;!!!'' ,`..`\"$$$c,`\"$$$$$cccc,.` .,,,.  `-.\n\
         <!!` c\"' z$P\"  `\"\"??h= \"$$$$$$P =???$$$,    `-\n\
       ;!!! d$$ccJ\".d$$$$$hc ?$$$,,.  .,,.\"\"=c $       `-.\n\
      <!!!! $$$$F ,,      \"\"h $$$$$F-?????$$c,            `.\n\
    ,c.`!!',$$$$ ?$$        $ 3$$$F        ,.\"              `\n\
  .c$$$ :! <$$$$L \"$L     ,c$ d$$$F        J$$'              `.\n\
  $$$$$ `!>`$$$$$$c,`\"????\"\",cP?$$L  ==ccc$$P'                 `.\n\
  $$$$$c !'<$$$$$$$$$hccccd$$$L;$$$h  c,,.,cc                    `.\n\
  ?$$$$',! J$$$$$$$$$$$$$$$$$$$$P\"\",c,`$$$$$$h                     :\n\
   \"$$' <'4$$$$$$$$$$$$$$$$$$$$$F,$$$$,$$$$$$$L.                    :\n\
     ;;!'.$$$$$$$$$$$$$$$$$$$$$$hcc:hh$$$$$$$$$$                     \\\n\
    '!!! $$$$$$$$$$$$$$F\"????????\"\"\"\"\"?$$$$$$$$$L                     \\\n\
     !! 4$$$$$$$$$$$$L,c  .,,,,,,,,,,. ?$$$$$$$$$                      `.\n\
     !>.$$$$$$$$$$$$$$$$L   `````````  J$$$$$$$$$.                       \\\n\
     !>`$$$$$$$$$$$$$$$$$$ `  ```````  J$$$$$$$$$'                       ;\n\
    '!! $$$$$$$$$$$$$$$$$$$$$$$$$ccccc??$$$$$$$$$                     . z$\n\
    <!! $$$$$$$$$$$$$$$$$$$$$$$cccccccc$$$$$$$$$$                   d$F.$$\n\
    !!! 3$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       ;;;;!!!!!! ,$P\"4$$\n\
    !!! `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ,;!!!!!!!!!'' ,xnnnn \"'.\n\
    !!!! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$P\"?$$$$$$$ !!!!!!!'',xdMMMMMMP ;!!!\n\
   ;!!!!>`$$$$$$$$$$$$$$$$$$$$$$$$$$$$ chc`3$$$$F,!'''',nnMMMMMMMP\" ;!!!!!\n\
   <!!!!! ?$$$$$$$$$$$$$$$$$$$$$$$$$$$hcccJ$$$P\" ,nMMMMMMMMMMMMP ;!!!!!!!!\n\
   !!!!!!> \"$$$$$$$$$$$$$$$$$$$$$$$$$$$$P\"\"\",xnMMMMMMMPPP\"\"\"'.  <!!!!!!!!!\n\
  ;!!!!!!!!; \"?$$$$$$$$$$$$$$$$$P\"\"'.,nmdMMM??\"\"\"..;;;;<!!!!!' <!!!!!!!!!\n\
  !!!!!!!!!!!;,.`\"\"???$$$??\"\"',,nn????\"\"\"...;;!'!!!!!!!!!!!!` <!!!!!!!!! ,\n\
  !!!!!!!!!!!!!!!!''`...-='\"...;;>-''``.    ;;  !!!!!!!!!! .<!!!!!!!!!! ,M\n\
 '!!!!!!!!''``  ,-='\"..;;;!''``..;;.    -'   ' !!!!!!!!!! ;!!!!!!!!!!' dMP\n\
 ''``..;;;;;!!'`  -```  .> `' ` ` ``' `..; ;!> !!!!!!!!' ;!!!!!!!!!!',MMM\n\
!!!!!!!!!!!!!! ; ''''' ''  -   <; --' ''''```..!!!!!!!' !!!!!!!!!!' uMM\" J\n\
'''.,xmnmmr `!> > >'..>  '  `.,;;;!!!!!!!!!!!!!!!!!!' ;!!!!!!!!!!',dMP uMM\n\
MMMMMPP\"\"\"  ;!! `  .,,;;!!!!!!!!!!''''''''''''!!!!! ;!!!!!!!!!!! uMMP MMMM\n\
MMM\",ndMMP  <!!!!!!!!!!!!!''``.,nmnMMMMMMMMMM !!!! <!!!!!!!!!!! uMMP dMMMM\n\
\" ,dMMMMMB  !!!!!!!'' .   .,,,,. \"44MMMMMMMM' !!!!!!!!!!!!!!!! uMMP dMMMMM\n\
 4MMMP\").r' !!!!'.,nP ,dMMMMMMMMMMb, 4MMMMM';!!!!!!!!!!!!!!!' JMP',dMMMMMM\n\
 4MP nMMM' '!!! uMMP MMMMMMMMMMMMMMMM,`MMM' !!!!!!!!!!!!!!! ;MMP dMMMMMMMM\n\
 .,nMP\".,= !!!! MMM dMMMMMMMMMMMMMMMMM M\" ;!!!!!!!!!!!!!!! nMM\".dMMMMMMMMM\n\
MMMMM'- ;!!!!!!!!!!!!!!!' dMP ;MMMMMMMMMMM\n\
,ndP\".;!!!!!!!!!!;; `4MMMMMMMMMMMMMP' ;<!!!!!!!!!!!!!!! -P\" ,dMMMMMMMMMMMM\n\
\"',;!!!!!!!!!!!!!!!!>;.`\"4MMMMMMP\" ;!!!!!!!!!!!!!!!'` ,xndMMMMMMMMMMMMMMMM\n\
!!!!!!!!!!!!!!!!!!!!!!!!!;;,..,,;<!!!!!!!!!!!''''.,nMMMMMMMMMMMMMMMMMMMMMM\n\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!' ,xnnMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'''.,,xn,`\"4MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\
!!!!!!!!!!!!!!!!!!!!!!!!!'''.,xnnMMMMMMMMMMn,`4MMMMMMMMMMMMMMMMMMMMMMMMMMM\n\
!!!!!!!!!!!!!!!!!!!!!''` -dMMMMMMMMMMMMMMMMMMM,\"4MMMMMMMMMMMMMMMMMMMMMMMMM\n\
```''!!!!!!''''''.,,nMMMMx \"MMMMMMMMMMMMMMMMMMMMx.\"\"44MMMMMMMMMMMMMMMMMMMM\n\
MMMmn,..,xmnmdMMMMMMMMMMMMMnx.\"4MMMMMMMMMMMMMMMMMMMMn.`\"4MMMMMMMMMMMMMMMMM\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMb,.\"4MMMMMMMMMMMMMMMMMMMMMx.\"4MMMMMMMMMMMMMM\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMbx.\"44MMMMMMMMMMMMMMMMMMMMx \"4MMMMMMMMMMM\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMn.\"\"4MMMMMMMMMMMMMMMMMMbx \"4MMMMMMMM";

const std::string CONST_WOODY_ASCII = "                                        .,,,.  ;>.;!!!!!> <!!!!!> ,;;,.\n\
                           ,    ..  !;<!!!!!!><!!!!!!!!!!!!!!!!!!!!!!!  ;\n\
                          !.;;!!!!;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.\n\
                       .,;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'\n\
                >' .;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\
               ;!;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'\n\
              .;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`\n\
        ,  ;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`\n\
       ;.;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!''''!!!!!!!!!'`\n\
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'''``.` .,;;-;> ;.'!!!!'\n\
     ,!!!!!!!!!!!!!!!!!!!!!!!!!!'''``.. -<.<!>'''.,;'` !! !!'\n\
  . <!!!!!!!!!!!!!!!!!!!!!!!'` ,> J$$$$$c- ``'''''.,c ; ` !\n\
  ';!!!!!!!!!!!!!!!!!!!!!''.;! ! J$$$P\".::::.\"$$$$$$$c < `\n\
  ;!!!!!!!!!!!!!!!!!!!'', <!! < J$P\"  _,ccc,.z$$$P\"\"\"?h `\n\
  !!!!!!!!!!!!!!!!!!!' <! ;! ; JC,,zr\" ..`\"$$$$$\" `\"'   ;\n\
 !!!!!!!!!!!!!!!!!!! ; '! ! ;! $$$$\" -???$,`$$$$\" `\"\"?$ ;\n\
 !!!!!!!!!!!!!!!!!!! !!!!,!,! d$$$F     cc, ?$$F ???c $\n\
,!!!!!!!!!!!!!!!!!!! ,cc !!! ,$$$$'     $$$ d$$    ,, P\n\
`!!!!!!!!!!!!!!!!!' J\",\"h !! $$$$C\" -,,d$P',$$$    d$ f\n\
 `!!!!!!!!!!!!!!!! J\",$L` ` ,$$$$$$$c, \"\" ,$$$$  ,c\" ,'\n\
 ,!!!!!!!!!!!!!!!! `c$\".  ' $$$$$$$$$$$cz$$$$$$..,,,d$.\n\
 '``''!!!!!!!!!'''!, $ \"h,. $$$$$$$$$$$$$$$$$$$h \"$$$$h\n\
      '              \"C,$$$$$$$$$$$$$$$$$P\"$$$$$h.`$$$$h\n\
                      3$$ $$$$$$$$$$$$$$$F-?????3$ 3$$$F\n\
                       \"  $$$$$$$$P\"\"3$$$$c,,.\"\"',c$$$$F\n\
                        ` $$$$$$$$.`\"??$$$$$$$$$$$$$$$P'\n\
                         <$$$$$$$$$$, =n,,,.`\"\"???? 3$F\n\
                         <$$$$$$$$$$$hc, `\"\"PPPPP : JF\n\
                          ?$$$$$$$$$$$$??c,`\"44n= ,J$\n\
                            \"?$$$$$$$$$h.`\"?hcczc??$'\n\
                            d,`?$$$$$$$$$$cc,,.,,cd$\n\
                            `$cc,\"?$$$$$$$$$$$$$$$$F\n\
                _,cccc==-    $$$$$c,\"??$$$$$$$$$$$$'\n\
                 `\"'.,ccc c\" .zc,,......`\"?$$$$$$$'\n\
              _,cd$$\".,,c, ;; ;;; ;.  \"\"?h,c, `L\n\
               `\"????\"\"\"\" xn,,,,,.`     .`\",r '$\n\
                        nMMP  \"\"??    ` .h ?cr-. \",$\n\
                        -,'            <!!; \"$ F   ,.\n\
              .,,,  .   c  c        .   ````      ,$$,\n\
       .,cch ?$$$$ J$$P ccr`. d$c, `4M.';'!!' c'.`?$$$c,.\n\
,c=\",c 3$$$$c $$P' `,cc ?\"  ? \"\"\"    ``   ;; ?$c > $$$$P'\n\
` c$$$L $$$$P \",cd\",P\".-,c$\"4          .  !!> \"\".! $\" \"F\n\
c,`$$$$,`\"',c,`$P' ,cd$ `\"C \"          4  ;;;;> ;.    ..\n\
$$.`$P'. $$$P\"  =-`\"',$$r'\"            4> `'''' ''-   '\\\n\
\"?\"  r?? \"\"           \"\"\".-            d>  !!!! ;;;     >\n\
                     ,`\",.    ,dMn,.,nMMB4 ``'' <!!    '> '.\n\
                    J\"  )MbnnMMMMMMMMMMM 4 !!'- ..`     \\ !`.h;";

static void	testConst(const Toy &t)
{
	(void)t.getName();
	(void)t.getType();
	(void)t.getAscii();
}

void	testToy(std::stringstream &out)
{
	(void)out;
	Toy	t;

	testConst(t);

	cr_assert_eq(t.getType(), Toy::ToyType::BASIC_TOY, "Default is a basic toy");
	cr_assert_eq(t.getName(), (std::string)"toy", "Default named 'toy'");
	cr_assert_eq(t.getAscii(), {}, "Default empty ascii art");

	t.setName("Basic toy");

	cr_assert_eq(t.getName(), (std::string)"Basic toy", "Checking setName");

	t.setAscii("art.txt");

	cr_assert_eq(t.getAscii(), (std::string)"This is an ascii art, I swear !", "Checking ascii art");

	Toy	t2(Toy::ToyType::ALIEN, "Malcome", "popo.txt");

	cr_assert_eq(t2.getType(), Toy::ToyType::ALIEN, "Alien type");
	cr_assert_eq(t2.getName(), (std::string)"Malcome", "Alien name");
	cr_assert_eq(t2.getAscii(), (std::string)"ERROR", "Ascii art error");

	t2.setAscii("empty.txt");

	cr_assert_eq(t2.getAscii(), {}, "Checking ascii art");
}

#if	TEST_EXO >= 1
void	testToy2(std::stringstream &out)
{
	(void)out;

	Toy t(Toy::ToyType::ALIEN, "Malcome", "popo.txt");
	Toy t1(Toy::ToyType::ALIEN, "Malcome2", "empty.txt");

	Toy t2 = t;

	cr_assert_eq(t2.getName(), (std::string)"Malcome", "Checking copy constructor");
	cr_assert_eq(t2.getAscii(), (std::string)"ERROR", "Ascii art copy init");

	t2 = t1;

	cr_assert_eq(t2.getName(), (std::string)"Malcome2", "Checking copy constructor");
	cr_assert_eq(t2.getAscii(), {}, "Ascii art copy");
}
#endif

#if	TEST_EXO >= 2

#include "Buzz.hpp"
#include "Woody.hpp"

void	testBaW(std::stringstream &out)
{
	(void)out;

	Buzz	b("baby");
	Woody	w("papy");

	cr_assert_eq(b.getType(), Toy::ToyType::BUZZ, "Buzz type");
	cr_assert_eq(b.getName(), (std::string)"baby", "Checking buzz name");
	cr_assert_eq(b.getAscii(), CONST_BUZZ_ASCII, "Buzz default ascii art");

	cr_assert_eq(w.getType(), Toy::ToyType::WOODY, "Woody type");
	cr_assert_eq(w.getName(), (std::string)"papy", "Checking woody name");
	cr_assert_eq(w.getAscii(), CONST_WOODY_ASCII, "Woody default ascii art");

	Buzz	b2("baby2", "empty.txt");
	Woody	w2("papy2", "empty.txt");

	cr_assert_eq(b2.getType(), Toy::ToyType::BUZZ, "Buzz type");
	cr_assert_eq(b2.getName(), (std::string)"baby2", "Checking buzz name");
	cr_assert_eq(b2.getAscii(), {}, "Buzz ascii art");

	cr_assert_eq(w2.getType(), Toy::ToyType::WOODY, "Woody type");
	cr_assert_eq(w2.getName(), (std::string)"papy2", "Checking woody name");
	cr_assert_eq(w2.getAscii(), {}, "Woody ascii art");

	Toy *tb = new Buzz("pb");
	Toy *tw = new Woody("pw");

	cr_assert_eq(tb->getType(), Toy::ToyType::BUZZ, "Buzz ptr type");
	cr_assert_eq(tb->getName(), (std::string)"pb", "Checking buzz's ptr name");

	cr_assert_eq(tw->getType(), Toy::ToyType::WOODY, "Woody ptr type");
	cr_assert_eq(tw->getName(), (std::string)"pw", "Checking woody's ptr name");

	delete tb;
	delete tw;
}
#endif
#if	TEST_EXO >= 3

void	testSpeak(std::stringstream &out)
{
	Toy		t(Toy::ToyType::BASIC_TOY, "Malcome", "empty.txt");
	Buzz	b("Yoann");
	Woody	w("Joanna");

	cr_assert_eq(t.getType(), Toy::ToyType::BASIC_TOY, "Toy type");
	cr_assert_eq(t.getName(), (std::string)"Malcome", "Checking Toy name");
	cr_assert_eq(t.getAscii(), {}, "Toy ascii art");

	cr_assert_eq(b.getType(), Toy::ToyType::BUZZ, "Buzz type");
	cr_assert_eq(b.getName(), (std::string)"Yoann", "Checking buzz name");
	cr_assert_eq(b.getAscii(), CONST_BUZZ_ASCII, "Buzz default ascii art");

	cr_assert_eq(w.getType(), Toy::ToyType::WOODY, "Woody type");
	cr_assert_eq(w.getName(), (std::string)"Joanna", "Checking woody name");
	cr_assert_eq(w.getAscii(), CONST_WOODY_ASCII, "Woody default ascii art");

	b.speak("Sur un mal-entendu ça peut passer...");

	cr_assert_line(out, "BUZZ: Yoann \"Sur un mal-entendu ça peut passer...\"", "Checking Buzz speak");

	w.speak("Tu peut m'aider ?");

	cr_assert_line(out, "WOODY: Joanna \"Tu peut m'aider ?\"", "Checking Woody speak");

	t.speak("La confiance n'exclus pas le contrôle.");

	cr_assert_line(out, "Malcome \"La confiance n'exclus pas le contrôle.\"", "Checking Toy speak");
}
#endif
#if	TEST_EXO >= 4

void	testOps(std::stringstream &out)
{
	Toy		t(Toy::ToyType::BASIC_TOY, "Malcome", "empty.txt");

	cr_assert_eq(t.getAscii(), {}, "Checking Ascii art");

	out << t;

	cr_assert_line(out, "Malcome", "Checking op<< Name");
	cr_assert_line(out, {}, "Checking op<< Ascii art");

	t << "-_-";

	cr_assert_eq(t.getAscii(), (std::string)"-_-", "Checking Ascii art");

	out << t;

	cr_assert_line(out, "Malcome", "Checking op<< Name");
	cr_assert_line(out, "-_-", "Checking op<< Ascii art");
}
#endif