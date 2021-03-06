Úkolem je vytvořit program, který pomůže optimalizovat emise dieselových motorů.

Po skandálu "dieselgate" přišla EU se souborem opatření, který si klade za cíl zvýšit transparentnost procesu homologace vznětových motorů. Nová norma EURO 666 určuje:

*   žádný z výrobců již nesmí lhát,
*   automobil musí být vybaven právě trojicí výfuků A, B a C,
*   spaliny se musí rozdělovat mezi jednotlivé výfuky,
*   měření emisí se provádí na každém výfuku zvlášť,

*   za rozhodující pro emise se považuje nejvyšší změřený obsah emisí z jednotlivých výfuků.

Nově vyvíjený motor má splnit požadavky EURO 666\. Z konstrukce vychází, že z různých ventilů je vypouštěné různé množství emisí, tyto hodnoty jsou známé pro každý z ventilů. Každý ventil musí být připojen do jednoho ze tří výfuků. Cílem programu je nalézt optimální propojení ventilů s jednotlivými výfuky tak, aby maximum naměřené přes jednotlivé výfuky bylo co nejnižší.

Vstupem programu je posloupnost celých kladných čísel. Tato čísla udávají množství emisí pro jednotlivé ventily. Zadávání hodnot končí po dosažení konce vstupu (EOF).

Program vyhodnotí možná propojení ventilů a zobrazí takové nalezené propojení, při kterém bude maximum z emisí přes výfuky co nejnižší. Bude zobrazena hodnota výfuku s nejvyššími emisemi a dále i seznam výfuků s příspěvky z jednotlivých ventilů (viz ukázka).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

*   nebyly zadané žádné ventily,
*   hodnota emisí pro ventil není číslo, je nulová nebo záporná.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu a velikostí dostupné paměti (limit je vidět v logu referenčního řešení). I když to na první pohled nevypadá, úloha je netriviální. Obecně nelze problém řešit jinak než otestováním všech možností. Zkoušení všech možností je časově náročné. Pro zvládnutí povinných testů postačuje rozumná implementace naivního řešení. Úloha nabízí i bonusové testy, které pracují s mnoha ventily. Pro takové vstupy je potřeba použít pokročilejší algoritmy, které dokáží eliminovat opakující se výpočty.

**Ukázka práce programu:**

* * *

<pre>Emise ventilu:
101 109 393 489 217
Nejvyssi emise: 489
A: 393
B: 101, 109, 217
C: 489
</pre>

* * *

<pre>Emise ventilu:
30 27 43 51 37 45 64
47 38 94 42 26 25 79 66
Nejvyssi emise: 238
A: 43, 37, 64, 94
B: 30, 27, 51, 45, 47, 38
C: 42, 26, 25, 79, 66
</pre>

* * *

<pre>Emise ventilu:
47 95 79 90 89 14 81 93
Nejvyssi emise: 207
A: 95, 90, 14
B: 93, 89
C: 81, 79, 47
</pre>

* * *

<pre>Emise ventilu:
-15
Nespravny vstup.
</pre>

* * *

**Poznámky:**

*   Správné řešení musí v nejhorším případě skutečně postihnout všechny možné kombinace. "Hladové" řešení se nemusí dopracovat ke správnému výsledku. To je vidět i v základních testech.
*   Rekurze je přirozeným způsobem k řešení tohoto typu úloh.
*   Při optimalizacích v bonusových testech můžete počítat s tím, že ventilů je mnoho (s malými emisemi) nebo naopak málo (s většími emisemi). Motor, který by měl mnoho ventilů s velkými emisemi, je nepřípustný. Žádný konstruktér si nedovolí takový ideozločin.
*   Pořadí hodnot ve výsledcích stejně jako označená výfuků (A/B/C) není určeno. Úloha navíc může mít mnoho stejně dobrých řešení. Testovací prostředí se vlastně vůbec nezajímá o pořadí ve výpisu ani o přiřazení ventilů k jednotlivým výfukům. Důležité je, aby všechny ventily byly někam zapojeny a aby se maximum součtů pro výfuky shodovalo s referencí.
*   Slovní popis struktury platných vstupních dat není zcela exaktní. Proto na výtky některých studentů přikládáme i popis vstupního jazyka v EBNF:

<pre>    input        ::= whiteSpace  positiveNumber { whiteSpace positiveNumber } whiteSpace
whiteSpace   ::= { ' ' | '\t' | '\n' }
number       ::= [ '+' ] { digit } nonzeroDigit { digit }
digit        ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
nonzeroDigit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
</pre>