Úkolem je realizovat funkci (ne celý program, pouze funkci), která bude počítat nešťastné pátky 13 v zadaném intervalu dat.

Pátek 13 bývá označován za nešťastný den. Samozřejmě, že je to jen pověra bez racionálního základu, kterou je potřeba zcela ignorovat. Ale přesto není radno podcenit třináctý pátek 13 ve svém životě. Nebo podcenit Progtestovou úlohu zadanou po pátku 13\. Zde pomůže požadovaná funkce.

Naše funkce dostane parametrem dvě data - počátek a konec časového intervalu, ve kterém hledáme pátky 13\. Počátek i konec je dán rokem, měsícem a dnem. Funkce spočítá, kolik pátků 13 bylo v zadaném intervalu (obě meze počítáme do intervalu, pokud některá mez je pátek 13, bude započtena).

Požadovaná funkce má rozhraní:

<pre>int CountFriday13 ( int y1, int m1, int d1,
int y2, int m2, int d2,
long long int * cnt )
</pre>

<dl>

<dt><tt>y1, m1, d1</tt></dt>

<dd>jsou vstupní parametry, které představují rok, měsíc a den počátku intervalu,</dd>

<dt><tt>y2, m2, d2</tt></dt>

<dd>jsou vstupní parametry, které představují rok, měsíc a den konce intervalu,</dd>

<dt><tt>cnt</tt></dt>

<dd>je výstupní parametr, do kterého funkce uloží vypočtený počet pátků 13 v zadaném období. Parametr bude funkce nastavovat pouze pokud jsou zadané správné vstupní parametry. Pokud jsou zadané nesprávné vstupy, nelze hodnotu určit. V takovém případě funkce signalizuje neúspěch a ponechá tento výstupní parametr beze změn. Vypočtená hodnota zahrnuje i případné pátky 13 v krajních bodech zadaného intervalu.</dd>

<dt>návratová hodnota funkce</dt>

<dd>bude nastavena na hodnotu 1 pro úspěch (správné vstupní parametry) nebo 0 pro neúspěch (nesprávné vstupní parametry).</dd>

</dl>

Pokud jsou zadané nesprávné vstupní parametry, je potřeba vrátit hodnotu 0 (neúspěch). Správné hodnoty vstupních parametrů musí splňovat:

*   rok je větší roven 1900,
*   měsíc je platný (1 až 12),
*   den je platný (1 až počet dní v měsíci),
*   zadaný okamžik počátku intervalu nenastane až po zadaném okamžiku konce intervalu.

Odevzdávejte zdrojový soubor, který obsahuje implementaci požadované funkce <tt>CountFriday13</tt>. Do zdrojového souboru přidejte i další Vaše podpůrné funkce, které jsou z <tt>CountFriday13</tt> volané. Funkce bude volaná z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkce. Za základ pro implementaci použijte kód z ukázky níže. V kódu chybí vyplnit funkci <tt>CountFriday13</tt> (a případné další podpůrné funkce). Ukázka obsahuje testovací funkci <tt>main</tt>, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce <tt>main</tt> jsou zabalené v bloku podmíněného překladu (<tt>#ifdef/#endif</tt>). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad Vám zjednoduší práci. Při kompilaci na Vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce <tt>main</tt> a vkládání hlavičkových souborů "zmizí", tedy nebude kolidovat s hlavičkovými soubory a funkcí <tt>main</tt> testovacího prostředí.

Při výpočtu času uvažujeme Gregoriánský kalendář. Tedy měsíce mají vždy 30 nebo vždy 31 dní, výjimkou je únor, který má 28 dní (nepřestupný rok) nebo 29 dní (přestupný rok). Podle Gregoriánského kalendáře platí:

1.  roky nejsou přestupné,
2.  s výjimkou let dělitelných 4, které jsou přestupné,
3.  s výjimkou let dělitelných 100, které nejsou přestupné,
4.  s výjimkou let dělitelných 400, které jsou přestupné,
5.  s výjimkou let dělitelných 4000, které nejsou přestupné.

Tedy roky 1901, 1902, 1903, 1905, ... jsou nepřestupné (pravidlo 1), roky 1904, 1908, ..., 1996, 2004, ... jsou přestupné (pravidlo 2), roky 1700, 1800, 1900, 2100, ... nejsou přestupné (pravidlo 3), roky 1600, 2000, 2400, ..., 3600, 4400, ... jsou přestupné (pravidlo 4) a roky 4000, 8000, ... nejsou přestupné (pravidlo 5).

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Časové limity jsou nastavené tak, aby rozumná implementace naivního algoritmu prošla všemi povinnými testy. Řešení fungující v povinných testech může získat nominálních 100% bodů. Bonusové testy vyžadují časově efektivní výpočet i pro velké intervaly (vysoké roky hodně převyšující 4000).

**Ukázka použití:**

* * *

<pre>#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int CountFriday13 ( int y1, int m1, int d1,
int y2, int m2, int d2, long long int * cnt )
{
/* todo */
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
long long int cnt;

assert ( CountFriday13 ( 1900,  1,  1,
2015,  1,  1, &cnt ) == 1
&& cnt == 197LL );
assert ( CountFriday13 ( 1900,  1,  1,
2015,  2,  1, &cnt ) == 1
&& cnt == 197LL );
assert ( CountFriday13 ( 1900,  1,  1,
2015,  1, 13, &cnt ) == 1
&& cnt == 197LL );
assert ( CountFriday13 ( 1900,  1,  1,
2015,  2, 13, &cnt ) == 1
&& cnt == 198LL );
assert ( CountFriday13 ( 1904,  1,  1,
2015,  1,  1, &cnt ) == 1
&& cnt == 189LL );
assert ( CountFriday13 ( 1904,  1,  1,
2015,  2,  1, &cnt ) == 1
&& cnt == 189LL );
assert ( CountFriday13 ( 1904,  1,  1,
2015,  1, 13, &cnt ) == 1
&& cnt == 189LL );
assert ( CountFriday13 ( 1904,  1,  1,
2015,  2, 13, &cnt ) == 1
&& cnt == 190LL );
assert ( CountFriday13 ( 1905,  2, 13,
2015,  1,  1, &cnt ) == 1
&& cnt == 187LL );
assert ( CountFriday13 ( 1905,  2, 13,
2015,  2,  1, &cnt ) == 1
&& cnt == 187LL );
assert ( CountFriday13 ( 1905,  2, 13,
2015,  1, 13, &cnt ) == 1
&& cnt == 187LL );
assert ( CountFriday13 ( 1905,  2, 13,
2015,  2, 13, &cnt ) == 1
&& cnt == 188LL );
assert ( CountFriday13 ( 1905,  1, 13,
2015,  1,  1, &cnt ) == 1
&& cnt == 188LL );
assert ( CountFriday13 ( 1905,  1, 13,
2015,  2,  1, &cnt ) == 1
&& cnt == 188LL );
assert ( CountFriday13 ( 1905,  1, 13,
2015,  1, 13, &cnt ) == 1
&& cnt == 188LL );
assert ( CountFriday13 ( 1905,  1, 13,
2015,  2, 13, &cnt ) == 1
&& cnt == 189LL );
assert ( CountFriday13 ( 2015, 11,  1,
2015, 10,  1, &cnt ) == 0 );
assert ( CountFriday13 ( 2015, 10, 32,
2015, 11, 10, &cnt ) == 0 );
assert ( CountFriday13 ( 2090,  2, 29,
2090,  2, 29, &cnt ) == 0 );
assert ( CountFriday13 ( 2096,  2, 29,
2096,  2, 29, &cnt ) == 1
&& cnt == 0LL );
assert ( CountFriday13 ( 2100,  2, 29,
2100,  2, 29, &cnt ) == 0 );
assert ( CountFriday13 ( 2000,  2, 29,
2000,  2, 29, &cnt ) == 1
&& cnt == 0LL );
return 0;
}
#endif /* __PROGTEST__ */
</pre>

* * *

**Nápověda:**

*   Zkopírujte si ukázku a použijte ji jako základ Vašeho řešení.
*   Do funkce <tt>main</tt> si můžete doplnit i další Vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
*   S trojicí hodnot (rok, měsíc, den) se špatně pracuje. Je lepší si tyto hodnoty převést na nějakou jinou reprezentaci, ideálně aby vzniklo pouze jedno číslo.
*   V programu musíte mnoho výpočtů dělat 2x - pro počátek a konec intervalu. Je dobrý nápad vytvořit si pomocné funkce, které 2x zavoláte.
*   V povinných testech jsou zadávané roky nepřevyšující rok 2100.
*   Pro velké intervaly (bonusový test) je celkový počet pátků 13 obrovský. Rozsah datového typu <tt>int</tt> nepostačuje. Proto má funkce parametrem <tt>long long int</tt>, který již stačí. Datový typ <tt>long long int</tt> není standardní součástí C89 (byl dodán později), proto kompilátor při jeho použití generuje varování. Toto varování se potlačí přepínačem <tt>-Wno-long-long</tt>. Progtest má tento přepínač nastaven, tedy použití tohoto datového typu nezpůsobí varování.
*   V ukázce je použito makro <tt>assert</tt>. Pokud je parametrem nenulová hodnota, makro nedělá nic. Pokud je parametrem nepravda (nula), makro ukončí program a vypíše řádku, kde k selhání došlo. Pokud tedy Vaše implementace projde ukázkovými testy, program doběhne a nic nezobrazí.