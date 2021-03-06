Úkolem je vytvořit program, který bude počítat a zobrazovat počty traťových dílců potřebných pro stavbu trati zadané délky.

Předpokládáme, že výrobce dodává traťové dílce dvou velikostí. Úkolem je určit počty potřebných traťových dílců jednotlivých velikostí, které jsou potřebné pro výstavbu trati zadané délky. Při stavbě trati musíme používat dílce vždy celé (nelze je krátit).

Vstupem programu je zadání délek vyráběných traťových dílců. Jedná se o dvě navzájem různá celá čísla. Po tomto vstupu následuje zadání délky trati ke stavbě. Pro zadanou délku trati program vypočte potřebné množství traťových dílců. Zadání délky je navíc dvojího druhu:

*   <tt>- délka</tt> pro toto zadání program zobrazí kolika různými způsoby lze traťové dílce kombinovat,
*   <tt>+ délka</tt> pro toto zadání program vypíše nalezené kombinace a zobrazí jejich počet.

Výstupem programu je počet možných způsobů, kterými lze zkombinovat traťové dílce pro zadanou vzdálenost. Podle vstupu (znaku + či - v zadání) se dále zobrazí či nezobrazí i výpis jednotlivých možných kombinací. Přesný formát výstupu je v ukázce níže. Pokud zadanou délku nelze z vyráběných dílců sestavit, program pro zadaný vstup vypíše informaci podle ukázky. Pozor, za výpisem je odřádkování (\n).

Pokud je vstup neplatný, program to musí detekovat, zobrazit chybové hlášení a ukončit se. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

*   délky vyráběných traťových dílců jsou nečíselné, záporné, nulové nebo jsou obě délky shodné,
*   při zadávání délky nebyl použit ani znak + ani - pro zapnutí/vypnutí úplného výpisu všech kombinací,
*   zadání délky trati je nečíselné nebo záporné.

Program v základní verzi pracuje s malými čísly, tedy k vyřešení stačí naivní algoritmus kontrolující přípustné možnosti. Pokud má být zobrazován kompletní výpis všech možných kombinací, nelze algoritmus příliš vylepšovat. Úloha nabízí nepovinný test. V tomto testu se testuje, zda řešení dokáže rychle počítat počty možných kombinací (pracuje pouze v režimu -, tedy bez výpisu všech nalezených kombinací). Pokud nepovinný test zvládnete, dostane řešení 100% bodů. Poud v programu použijete pouze naivní algoritmus, nepovinným testem neprojdete a získáte méně než 100% bodů.

Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (edux -> výuková videa), jak testovací data použít a jak testování zautomatizovat.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít v povinných testech problém). Zvládnutí nepovinného testu již vyžaduje lepší algoritmus. Testovací prostředí dále zakazuje používat některé "nebezpečné funkce" -- funkce pro spouštění programu, pro práci se sítí, ... Pokud jsou tyto funkce použité, program se nespustí. Možná ve svém programu používáte volání:

<pre>int main ( int argc, char * argv [] )
{

...

system ( "pause" ); /* aby se nezavrelo okno programu */
return 0;
}
</pre>

Toto nebude v testovacím prostředí fungovat - je zakázáno spouštění jiného programu. (I pokud by se program spustil, byl by odmítnut. Nebyl by totiž nikdo, kdo by pauzu "odmáčkl", program by čekal věčně a překročil by tak maximální dobu běhu.) Pokud tedy chcete zachovat pauzu pro testování na Vašem počítači a zároveň chcete mít jistotu, že program poběží správně, použijte následující trik:

<pre>int main ( int argc, char * argv [] )
{

...

#ifndef __PROGTEST__
system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
return 0;
}
</pre>

**Ukázka práce programu:**

* * *

<pre>Delky koleji:
10 13
Vzdalenost:
+ 100
= 10 * 10 + 13 * 0
Celkem variant: 1
</pre>

* * *

<pre>Delky koleji:
10 13
Vzdalenost:
+ 749
= 10 * 32 + 13 * 33
= 10 * 19 + 13 * 43
= 10 * 6 + 13 * 53
= 10 * 71 + 13 * 3
= 10 * 58 + 13 * 13
= 10 * 45 + 13 * 23
Celkem variant: 6
</pre>

* * *

<pre>Delky koleji:
10 13
Vzdalenost:
+ 71
Reseni neexistuje.
</pre>

* * *

<pre>Delky koleji:
10 13
Vzdalenost:
+ 0
= 10 * 0 + 13 * 0
Celkem variant: 1
</pre>

* * *

<pre>Delky koleji:
54 16
Vzdalenost:
+ 121
Reseni neexistuje.
</pre>

* * *

<pre>Delky koleji:
54 16
Vzdalenost:
+ 2400
= 54 * 16 + 16 * 96
= 54 * 8 + 16 * 123
= 54 * 0 + 16 * 150
= 54 * 40 + 16 * 15
= 54 * 32 + 16 * 42
= 54 * 24 + 16 * 69
Celkem variant: 6
</pre>

* * *

<pre>Delky koleji:
173 459
Vzdalenost:
- 5219
Reseni neexistuje.
</pre>

* * *

<pre>Delky koleji:
173 459
Vzdalenost:
- 234875
Celkem variant: 3
</pre>

* * *

<pre>Delky koleji:
22 33
Vzdalenost:
* 12
Nespravny vstup.
</pre>

* * *

<pre>Delky koleji:
10 abc
Nespravny vstup.
</pre>

* * *

**Poznámky:**

*   Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
*   Výpis nalezených kombinací (pokud je požadován) nemá určené pořadí. Testovací prostředí si v případě potřeby pořadí před porovnáním prohodí. Tedy například pro dílce délky <tt>13 17</tt> a požadovanou délku tratě 7111 jsou za správné považované následující výpisy:

<pre>   = 13 * 190 + 17 * 273
= 13 * 428 + 17 * 91
= 13 * 105 + 17 * 338
= 13 * 343 + 17 * 156
= 13 * 20 + 17 * 403
= 13 * 258 + 17 * 221
= 13 * 496 + 17 * 39
= 13 * 173 + 17 * 286
= 13 * 411 + 17 * 104
= 13 * 88 + 17 * 351
= 13 * 326 + 17 * 169
= 13 * 3 + 17 * 416
= 13 * 241 + 17 * 234
= 13 * 479 + 17 * 52
= 13 * 156 + 17 * 299
= 13 * 394 + 17 * 117
= 13 * 71 + 17 * 364
= 13 * 309 + 17 * 182
= 13 * 547 + 17 * 0
= 13 * 224 + 17 * 247
= 13 * 462 + 17 * 65
= 13 * 139 + 17 * 312
= 13 * 377 + 17 * 130
= 13 * 54 + 17 * 377
= 13 * 292 + 17 * 195
= 13 * 530 + 17 * 13
= 13 * 207 + 17 * 260
= 13 * 445 + 17 * 78
= 13 * 122 + 17 * 325
= 13 * 360 + 17 * 143
= 13 * 37 + 17 * 390
= 13 * 275 + 17 * 208
= 13 * 513 + 17 * 26
Celkem variant: 33
</pre>

* * *

<pre>   = 13 * 428 + 17 * 91
= 13 * 190 + 17 * 273
= 13 * 105 + 17 * 338
= 13 * 343 + 17 * 156
= 13 * 20 + 17 * 403
= 13 * 258 + 17 * 221
= 13 * 496 + 17 * 39
= 13 * 173 + 17 * 286
= 13 * 411 + 17 * 104
= 13 * 88 + 17 * 351
= 13 * 326 + 17 * 169
= 13 * 3 + 17 * 416
= 13 * 241 + 17 * 234
= 13 * 479 + 17 * 52
= 13 * 156 + 17 * 299
= 13 * 394 + 17 * 117
= 13 * 71 + 17 * 364
= 13 * 309 + 17 * 182
= 13 * 547 + 17 * 0
= 13 * 224 + 17 * 247
= 13 * 462 + 17 * 65
= 13 * 139 + 17 * 312
= 13 * 377 + 17 * 130
= 13 * 54 + 17 * 377
= 13 * 292 + 17 * 195
= 13 * 530 + 17 * 13
= 13 * 207 + 17 * 260
= 13 * 445 + 17 * 78
= 13 * 122 + 17 * 325
= 13 * 360 + 17 * 143
= 13 * 37 + 17 * 390
= 13 * 275 + 17 * 208
= 13 * 513 + 17 * 26
Celkem variant: 33
</pre>

* * *

<pre>   = 13 * 20 + 17 * 403
= 13 * 428 + 17 * 91
= 13 * 190 + 17 * 273
= 13 * 105 + 17 * 338
= 13 * 343 + 17 * 156
= 13 * 258 + 17 * 221
= 13 * 496 + 17 * 39
= 13 * 173 + 17 * 286
= 13 * 411 + 17 * 104
= 13 * 88 + 17 * 351
= 13 * 326 + 17 * 169
= 13 * 3 + 17 * 416
= 13 * 241 + 17 * 234
= 13 * 479 + 17 * 52
= 13 * 156 + 17 * 299
= 13 * 394 + 17 * 117
= 13 * 71 + 17 * 364
= 13 * 309 + 17 * 182
= 13 * 547 + 17 * 0
= 13 * 224 + 17 * 247
= 13 * 462 + 17 * 65
= 13 * 139 + 17 * 312
= 13 * 377 + 17 * 130
= 13 * 54 + 17 * 377
= 13 * 292 + 17 * 195
= 13 * 530 + 17 * 13
= 13 * 207 + 17 * 260
= 13 * 445 + 17 * 78
= 13 * 122 + 17 * 325
= 13 * 360 + 17 * 143
= 13 * 37 + 17 * 390
= 13 * 275 + 17 * 208
= 13 * 513 + 17 * 26
Celkem variant: 33
</pre>

a libovolná další ze zbývajících 8683317618811886495518194401279999997 permutací.
*   Při kontrole výstupů Vašeho programu nelze přímo porovnávat Váš výpis a referenční výpis. Před porovnáním budete nejspíše muset upravit pořadí nalezených kombinací. Odpovídající nástroje jsou probírané v BI-PS1.
*   Při programování si dejte pozor na rozsah použitých datových typů. Pro povinné testy lze vystačit s datovým typem <tt>int</tt>. Pokud chcete projít i nepovinným testem, je potřeba používat datový typ s větším rozsahem (<tt>long long</tt>).
*   Použití datového typu <tt>long long</tt> je možné. Kompilátor je nastaven tak, aby jeho použití negenerovalo varování (přepínač <tt>-Wno-long-long</tt>).
*   Pro načtení znaménka +/- ze vstupu se hodí formát <tt>"%c"</tt> nebo <tt>" %c"</tt>. Rozdíl mezi těmito konverzemi je dobře popsaný v manuálu k funkci <tt>scanf</tt>.
*   Slovní popis struktury platných vstupních dat není zcela exaktní. Proto na výtky některých studentů přikládáme i popis vstupního jazyka v EBNF:

<pre>    input      ::= { whiteSpace } number { whiteSpace } number { whiteSpace } [ '+' | '-' ]
whiteSpace { whiteSpace } number { whiteSpace }
whiteSpace ::= ' ' | '\t' | '\n' | '\r'
number     ::= [ '+' ] digit { digit }
digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
</pre>

Poznámka: EBNF nedokáže zachytit statickou sémantiku. Tedy např. v EBNF není zachycena skutečnost, že délky traťových dílců jsou navzájem různé.