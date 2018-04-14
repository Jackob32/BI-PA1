Úkolem je vytvořit program, který pomůže obsluze radaru řídící věže.

Při řízení letového provozu je důležité hlídat potenciální kolize letadel. Radary snímají pozice letadel a program kontroluje vzdálenosti mezi letadly. Chceme realizovat program, který pro zadané souřadnice letadel rozhodne, kde hrozí potenciální kolize, tedy která letadla jsou k sobě nejblíže.

Vstupem programu jsou souřadnice letadel. Pro jednoduchost předpokládáme, že souřadnice letadle jsou rovinné, tedy pozice letadla je určena <tt>x</tt> a <tt>y</tt> souřadnicí. Souřadnice mají podobu desetinných čísel. Souřadnic může být na vstupu velmi mnoho, jejich počet není dopředu známý. Zadávání souřadnic končí s aktivním koncem souboru (EOF na stdin). Formát vstupu je zřejmý z ukázek níže.

Výstupem program je vzdálenost dvojice nejbližších letadel. Pokud je v té samé (nejmenší) vzdálenosti více dvojic letadel, program vypíše počet dvojic letadel v této (nejmenší) vzdálenosti.

Program musí ošetřovat vstupní data. Pokud jsou vstupní data nesprávná, program to zjistí, zobrazí chybové hlášení a ukončí se. Za chybu je považováno:

*   nečíselné souřadnice,
*   chybějící/přebývající hranaté závorky nebo čárka,
*   méně než dvě letadla na vstupu (jinak není definovaná nejmenší vzdálenost).

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Testovací prostředí dále zakazuje používat některé "nebezpečné funkce" -- funkce pro spouštění programu, pro práci se sítí, ... Pokud jsou tyto funkce použité, program se nespustí.

V závislosti na zvoleném algoritmu může být úloha výpočetně náročnější. Správná implementace naivního algoritmu projde všemi testy kromě testu bonusového, tedy má šanci získat nominálních 100% bodů. Pro zvládnutí bonusového testu je potřeba použít efektivnější algoritmus, který dokáže v krátkém čase zvládnout větší objem testovacích dat (velké množství letadel).

**Ukázka práce programu:**

* * *

<pre>Zadejte souradnice:
[0,0] [5, 0] [10, 0] [7, 0] [2,0]
Vzdalenost nejblizsich letadel: 2
Nalezenych dvojic: 2
</pre>

* * *

<pre>Zadejte souradnice:
[0,5] [5,0] [0,0] [5,5] [2.5,2.5]
Vzdalenost nejblizsich letadel: 3.53553
Nalezenych dvojic: 4
</pre>

* * *

<pre>Zadejte souradnice:
[-10,-5] [10,0] [12,12]
Vzdalenost nejblizsich letadel: 12.1655
Nalezenych dvojic: 1
</pre>

* * *

<pre>Zadejte souradnice:
[-1000000,0] [1000000,0] [5000000,0]
Vzdalenost nejblizsich letadel: 2e+06
Nalezenych dvojic: 1
</pre>

* * *

<pre>Zadejte souradnice:
[10,10] [10,10] [20, 20] [20,20] [20,20] [10,10]
Vzdalenost nejblizsich letadel: 0
Nalezenych dvojic: 6
</pre>

* * *

<pre>Zadejte souradnice:
[3,abc]
Nespravny vstup.
</pre>

* * *

<pre>Zadejte souradnice:
[0,0] [5,8 [10,10]
Nespravny vstup.
</pre>

* * *

**Poznámky:**  

*   Pro reprezentaci letadel si budete muset alokovat prostor dynamicky.
*   Velikost není známá dopředu. Paměť pro prvky budete muset alokovat postupně a budete muset alokovanou paměť postupně zvětšovat. Hodí se k tomu funkce <tt>realloc</tt>.
*   Při alokaci nemíchejte C funkce (<tt>malloc</tt>, <tt>realloc</tt>, <tt>free</tt>) a C++ operátory pro alokaci (<tt>new</tt>, <tt>delete</tt>). Míchání C a C++ stylu není rozumné, při testování takový program nejspíše spadne.
*   Nepoužívejte C++ knihovnu STL (<tt>vector</tt>, <tt>list</tt>, ...). Účelem je procvičit dynamickou alokaci paměti v C. STL budete používat v předmětu PA2, v PA1 je použití STL zakázané. Pokud přesto STL použijete, Váš program nepůjde přeložit.
*   V jednom z testů se kontrolují přístupy do paměti a kontroluje se uvolňování dynamicky alokované paměti. Pokud dynamicky alokovanou paměť neuvolníte, bude Váš výsledek zatížen bodovým malusem.
*   Nalezenou vzdálenost zobrazujte v semilogaritmickém tvaru (formát <tt>%g</tt>).
