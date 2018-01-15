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

const std::string CONST_BUZZ_ASCII = "      __...-=--=-=--=---=---=-..__\
 .,--~                            ~~--.._\
'                .,;;!!!!!!!;;,,,.       `--._\
             ;;!!'`.,,,,.````````'''>>;;,     `-._\
          ;!!!'' ,`..`\"$$$c,`\"$$$$$cccc,.` .,,,.  `-.\
         <!!` c\"' z$P\"  `\"\"??h= \"$$$$$$P =???$$$,    `-\
       ;!!! d$$ccJ\".d$$$$$hc ?$$$,,.  .,,.\"\"=c $       `-.\
      <!!!! $$$$F ,,      \"\"h $$$$$F-?????$$c,            `.\
    ,c.`!!',$$$$ ?$$        $ 3$$$F        ,.\"              `\
  .c$$$ :! <$$$$L \"$L     ,c$ d$$$F        J$$'              `.\
  $$$$$ `!>`$$$$$$c,`\"????\"\",cP?$$L  ==ccc$$P'                 `.\
  $$$$$c !'<$$$$$$$$$hccccd$$$L;$$$h  c,,.,cc                    `.\
  ?$$$$',! J$$$$$$$$$$$$$$$$$$$$P\"\",c,`$$$$$$h                     :\
   \"$$' <'4$$$$$$$$$$$$$$$$$$$$$F,$$$$,$$$$$$$L.                    :\
     ;;!'.$$$$$$$$$$$$$$$$$$$$$$hcc:hh$$$$$$$$$$                     \\\
    '!!! $$$$$$$$$$$$$$F\"????????\"\"\"\"\"?$$$$$$$$$L                     \\\
     !! 4$$$$$$$$$$$$L,c  .,,,,,,,,,,. ?$$$$$$$$$                      `.\
     !>.$$$$$$$$$$$$$$$$L   `````````  J$$$$$$$$$.                       \\\
     !>`$$$$$$$$$$$$$$$$$$ `  ```````  J$$$$$$$$$'                       ;\
    '!! $$$$$$$$$$$$$$$$$$$$$$$$$ccccc??$$$$$$$$$                     . z$\
    <!! $$$$$$$$$$$$$$$$$$$$$$$cccccccc$$$$$$$$$$                   d$F.$$\
    !!! 3$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       ;;;;!!!!!! ,$P\"4$$\
    !!! `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ,;!!!!!!!!!'' ,xnnnn \"'.\
    !!!! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$P\"?$$$$$$$ !!!!!!!'',xdMMMMMMP ;!!!\
   ;!!!!>`$$$$$$$$$$$$$$$$$$$$$$$$$$$$ chc`3$$$$F,!'''',nnMMMMMMMP\" ;!!!!!\
   <!!!!! ?$$$$$$$$$$$$$$$$$$$$$$$$$$$hcccJ$$$P\" ,nMMMMMMMMMMMMP ;!!!!!!!!\
   !!!!!!> \"$$$$$$$$$$$$$$$$$$$$$$$$$$$$P\"\"\",xnMMMMMMMPPP\"\"\"'.  <!!!!!!!!!\
  ;!!!!!!!!; \"?$$$$$$$$$$$$$$$$$P\"\"'.,nmdMMM??\"\"\"..;;;;<!!!!!' <!!!!!!!!!\
  !!!!!!!!!!!;,.`\"\"???$$$??\"\"',,nn????\"\"\"...;;!'!!!!!!!!!!!!` <!!!!!!!!! ,\
  !!!!!!!!!!!!!!!!''`...-='\"...;;>-''``.    ;;  !!!!!!!!!! .<!!!!!!!!!! ,M\
 '!!!!!!!!''``  ,-='\"..;;;!''``..;;.    -'   ' !!!!!!!!!! ;!!!!!!!!!!' dMP\
 ''``..;;;;;!!'`  -```  .> `' ` ` ``' `..; ;!> !!!!!!!!' ;!!!!!!!!!!',MMM\
!!!!!!!!!!!!!! ; ''''' ''  -   <; --' ''''```..!!!!!!!' !!!!!!!!!!' uMM\" J\
'''.,xmnmmr `!> > >'..>  '  `.,;;;!!!!!!!!!!!!!!!!!!' ;!!!!!!!!!!',dMP uMM\
MMMMMPP\"\"\"  ;!! `  .,,;;!!!!!!!!!!''''''''''''!!!!! ;!!!!!!!!!!! uMMP MMMM\
MMM\",ndMMP  <!!!!!!!!!!!!!''``.,nmnMMMMMMMMMM !!!! <!!!!!!!!!!! uMMP dMMMM\
\" ,dMMMMMB  !!!!!!!'' .   .,,,,. \"44MMMMMMMM' !!!!!!!!!!!!!!!! uMMP dMMMMM\
 4MMMP\").r' !!!!'.,nP ,dMMMMMMMMMMb, 4MMMMM';!!!!!!!!!!!!!!!' JMP',dMMMMMM\
 4MP nMMM' '!!! uMMP MMMMMMMMMMMMMMMM,`MMM' !!!!!!!!!!!!!!! ;MMP dMMMMMMMM\
 .,nMP\".,= !!!! MMM dMMMMMMMMMMMMMMMMM M\" ;!!!!!!!!!!!!!!! nMM\".dMMMMMMMMM\
MMMMM'- ;!!!!!!!!!!!!!!!' dMP ;MMMMMMMMMMM\
,ndP\".;!!!!!!!!!!;; `4MMMMMMMMMMMMMP' ;<!!!!!!!!!!!!!!! -P\" ,dMMMMMMMMMMMM\
\"',;!!!!!!!!!!!!!!!!>;.`\"4MMMMMMP\" ;!!!!!!!!!!!!!!!'` ,xndMMMMMMMMMMMMMMMM\
!!!!!!!!!!!!!!!!!!!!!!!!!;;,..,,;<!!!!!!!!!!!''''.,nMMMMMMMMMMMMMMMMMMMMMM\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!' ,xnnMMMMMMMMMMMMMMMMMMMMMMMMMMMM\
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'''.,,xn,`\"4MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\
!!!!!!!!!!!!!!!!!!!!!!!!!'''.,xnnMMMMMMMMMMn,`4MMMMMMMMMMMMMMMMMMMMMMMMMMM\
!!!!!!!!!!!!!!!!!!!!!''` -dMMMMMMMMMMMMMMMMMMM,\"4MMMMMMMMMMMMMMMMMMMMMMMMM\
```''!!!!!!''''''.,,nMMMMx \"MMMMMMMMMMMMMMMMMMMMx.\"\"44MMMMMMMMMMMMMMMMMMMM\
MMMmn,..,xmnmdMMMMMMMMMMMMMnx.\"4MMMMMMMMMMMMMMMMMMMMn.`\"4MMMMMMMMMMMMMMMMM\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMb,.\"4MMMMMMMMMMMMMMMMMMMMMx.\"4MMMMMMMMMMMMMM\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMbx.\"44MMMMMMMMMMMMMMMMMMMMx \"4MMMMMMMMMMM\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMn.\"\"4MMMMMMMMMMMMMMMMMMbx \"4MMMMMMMM";

const std::string CONST_WOODY_ASCII = "                                        .,,,.  ;>.;!!!!!> <!!!!!> ,;;,.\
                           ,    ..  !;<!!!!!!><!!!!!!!!!!!!!!!!!!!!!!!  ;\
                          !.;;!!!!;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.\
                       .,;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'\
                >' .;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
               ;!;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'\
              .;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`\
        ,  ;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`\
       ;.;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!''''!!!!!!!!!'`\
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'''``.` .,;;-;> ;.'!!!!'\
     ,!!!!!!!!!!!!!!!!!!!!!!!!!!'''``.. -<.<!>'''.,;'` !! !!'\
  . <!!!!!!!!!!!!!!!!!!!!!!!'` ,> J$$$$$c- ``'''''.,c ; ` !\
  ';!!!!!!!!!!!!!!!!!!!!!''.;! ! J$$$P\".::::.\"$$$$$$$c < `\
  ;!!!!!!!!!!!!!!!!!!!'', <!! < J$P\"  _,ccc,.z$$$P\"\"\"?h `\
  !!!!!!!!!!!!!!!!!!!' <! ;! ; JC,,zr\" ..`\"$$$$$\" `\"'   ;\
 !!!!!!!!!!!!!!!!!!! ; '! ! ;! $$$$\" -???$,`$$$$\" `\"\"?$ ;\
 !!!!!!!!!!!!!!!!!!! !!!!,!,! d$$$F     cc, ?$$F ???c $\
,!!!!!!!!!!!!!!!!!!! ,cc !!! ,$$$$'     $$$ d$$    ,, P\
`!!!!!!!!!!!!!!!!!' J\",\"h !! $$$$C\" -,,d$P',$$$    d$ f\
 `!!!!!!!!!!!!!!!! J\",$L` ` ,$$$$$$$c, \"\" ,$$$$  ,c\" ,'\
 ,!!!!!!!!!!!!!!!! `c$\".  ' $$$$$$$$$$$cz$$$$$$..,,,d$.\
 '``''!!!!!!!!!'''!, $ \"h,. $$$$$$$$$$$$$$$$$$$h \"$$$$h\
      '              \"C,$$$$$$$$$$$$$$$$$P\"$$$$$h.`$$$$h\
                      3$$ $$$$$$$$$$$$$$$F-?????3$ 3$$$F\
                       \"  $$$$$$$$P\"\"3$$$$c,,.\"\"',c$$$$F\
                        ` $$$$$$$$.`\"??$$$$$$$$$$$$$$$P'\
                         <$$$$$$$$$$, =n,,,.`\"\"???? 3$F\
                         <$$$$$$$$$$$hc, `\"\"PPPPP : JF\
                          ?$$$$$$$$$$$$??c,`\"44n= ,J$\
                            \"?$$$$$$$$$h.`\"?hcczc??$'\
                            d,`?$$$$$$$$$$cc,,.,,cd$\
                            `$cc,\"?$$$$$$$$$$$$$$$$F\
                _,cccc==-    $$$$$c,\"??$$$$$$$$$$$$'\
                 `\"'.,ccc c\" .zc,,......`\"?$$$$$$$'\
              _,cd$$\".,,c, ;; ;;; ;.  \"\"?h,c, `L\
               `\"????\"\"\"\" xn,,,,,.`     .`\",r '$\
                        nMMP  \"\"??    ` .h ?cr-. \",$\
                        -,'            <!!; \"$ F   ,.\
              .,,,  .   c  c        .   ````      ,$$,\
       .,cch ?$$$$ J$$P ccr`. d$c, `4M.';'!!' c'.`?$$$c,.\
,c=\",c 3$$$$c $$P' `,cc ?\"  ? \"\"\"    ``   ;; ?$c > $$$$P'\
` c$$$L $$$$P \",cd\",P\".-,c$\"4          .  !!> \"\".! $\" \"F\
c,`$$$$,`\"',c,`$P' ,cd$ `\"C \"          4  ;;;;> ;.    ..\
$$.`$P'. $$$P\"  =-`\"',$$r'\"            4> `'''' ''-   '\\\
\"?\"  r?? \"\"           \"\"\".-            d>  !!!! ;;;     >\
                     ,`\",.    ,dMn,.,nMMB4 ``'' <!!    '> '.\
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