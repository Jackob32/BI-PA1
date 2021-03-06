***Not 100% finished***
Vaším úkolem je vytvořit funkci (ne program, pouze funkci), která dokáže pomoci PR oddělení při formulaci politicky korektních tiskových prohlášení.

S rozvojem naší společnosti je spojená nutnost formulovat své myšlenky tak, aby prohlášení nemohlo nikoho ranit či dokonce urazit. Tomuto trendu se říká politická korektnost, lidově též newspeak. Podobnost s pojmem newspeak z Orwellova románu je pochopitelně čistě náhodná. Označit někoho za "flákače" je prostě nepřípustné, naproti tomu pojem "osoba se specifickou potřebou plánování účasti v pracovním procesu" je zcela jistě univerzálně použitelné.

Vámi implementovaná funkce tomuto procesu bude napomáhat. Vypisovat dlouhé politicky korektní fráze odmítají i osoby bez specifických potřeb plánování účasti v pracovním procesu. Implementovaná funkce bude v textu nahrazovat nevhodné politicky nekorektní formulace za jejich správnou náhradu. Rozhraní funkce bude:

<pre>char * newSpeak ( const char * text, const char * (*replace)[2] );
</pre>

Parametry funkce jsou:

*   <tt>text</tt> - původní text, ve kterém má dojít k náhradě nevhodných formulací. Tento parametr je <tt>const</tt>, tedy funkce jej může pouze číst,
*   <tt>replace</tt> - je pole s dvojicemi řetězců, k nahrazení. Pole <tt>replace</tt> je dvojrozměrné, obsahuje <tt>n</tt> řádek a dva sloupce. Ve sloupci 0 je řetězec nevhodné fráze a ve sloupci 1 je její politicky korektní náhrada. Počet řádek pole není explicitně určen, víte ale, že poslední řádka v poli obsahuje dva ukazatele s hodnotou <tt>NULL</tt>.
*   Návratovou hodnotou funkce je řetězec s provedenými náhradami. Tento řetězec musí být funkcí dynamicky alokován (buď <tt>malloc</tt> nebo <tt>realloc</tt>). Volající řetězec použije a po jeho použití jej uvolní z paměti (zavolá <tt>free</tt>). V případě chybných parametrů vrací funkce <tt>NULL</tt>.

Chceme, aby náhrady v řetězci byly jednoznačné. Toho dosáhneme následujícím:

*   text nahrazujeme zleva doprava,
*   jednou nahrazený text již není znovu nahrazován, v náhradách pokračujeme za nahrazeným textem (viz např. ukázka "specialist"),
*   nahrazované fráze (sloupec 0) jsou jednoznačné, tedy žádný vzor nesmí být předponou jiného vzoru. Funkce před zahájením práce zkontroluje, že toto platí, pokud ne, vrátí chybovou signalizaci hodnotou <tt>NULL</tt>. V ukázkovém běhu je to porušeno u dvojice <tt>fail</tt> a <tt>failure</tt>.

Všechny řetězce, které funkce dostává/vrací jsou ASCIIZ řetězce (nulou ukončené). Při porovnávání řetězců funkce rozlišuje malá a velká písmenka.

Odevzdávejte zdrojový soubor, který obsahuje implementaci požadované funkce <tt>newSpeak</tt>. Do zdrojového souboru přidejte i další Vaše podpůrné funkce, které jsou z <tt>newSpeak</tt> volané. Funkce bude volaná z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkce. Za základ pro implementaci použijte kód z ukázky níže. V kódu chybí vyplnit funkci <tt>newSpeak</tt> (a případné další podpůrné funkce). Ukázka obsahuje testovací funkci <tt>main</tt>, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce <tt>main</tt> jsou zabalené v bloku podmíněného překladu (<tt>#ifdef/#endif</tt>). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad Vám zjednoduší práci. Při kompilaci na Vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce <tt>main</tt> a vkládání hlavičkových souborů "zmizí", tedy nebude kolidovat s hlavičkovými soubory a funkcí <tt>main</tt> testovacího prostředí.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Časové limity jsou nastavené tak, aby rozumná implementace naivního algoritmu prošla všemi povinnými testy. Řešení fungující v povinných testech může získat nominálních 100% bodů. Bonusový test vyžaduje časově a paměťově efektivní výpočet i pro dlouhé řetězce obsahující mnoho slov a slovníky obsahující stovky dlouhých frází. První bonus kontroluje rychlost, druhý paměťovou náročnost.

Pro implementaci musíte použít C řetězce. C++ řetězce (<tt>std::string</tt>) a STL jsou zakázané, jejich použití povede k chybě při kompilaci.

**Ukázka použití funkce:**  

* * *

<pre>#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif /* __PROGTEST__ */

char * newSpeak ( const char * text, const char * (*replace)[2] )
 {
   /* todo */
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   char * res;

   const char * d1 [][2] = {
     { "murderer", "termination specialist" },
     { "failure", "non-traditional success" },
     { "specialist", "person with certified level of knowledge" },
     { "dumb", "cerebrally challenged" },
     { "teacher", "voluntary knowledge conveyor" },
     { "evil", "nicenest deprived" },
     { "incorrect answer", "alternative answer" },
     { "student", "client" },
     { NULL, NULL }
    };

   const char * d2 [][2] = {
     { "fail", "suboptimal result" },
     { "failure", "non-traditional success" },
     { NULL, NULL }
    };

   res = newSpeak ( "Everybody is happy.", d1 );
   /* res = "Everybody is happy."*/
   free ( res );

   res = newSpeak ( "The student answered an incorrect answer.", d1 );
   /* res = "The client answered an alternative answer."*/
   free ( res );

   res = newSpeak ( "He was dumb, his failure was expected.", d1 );
   /* res = "He was cerebrally challenged, his non-traditional success was expected."*/
   free ( res );

   res = newSpeak ( "The evil teacher became a murderer.", d1 );
   /* res = "The nicenest deprived voluntary knowledge conveyor became a termination specialist."*/
   free ( res );

   res = newSpeak ( "Devil's advocate.", d1 );
   /* res = "Dnicenest deprived's advocate."*/
   free ( res );

   res = newSpeak ( "Hello.", d2 );
   /* res = NULL */

   return 0;
 }
#endif /* __PROGTEST__ */
</pre>
