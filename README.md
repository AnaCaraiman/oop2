# Descrierea proiectului pentru utilizator

Proiectul este o aplicație scrisă în C++ care simulează funcționarea unei florării moderne. Utilizatorul joacă rolul administratorului florăriei și are la dispoziție un buget inițial pentru a configura stocul de flori, accesorii și cutii, precum și pentru a prelua comenzi de la clienți. Comenzile pot fi de mai multe tipuri: buchete simple, buchete premium sau aranjamente florale, fiecare având o structură proprie de compunere, un cost asociat și reguli stricte de verificare a stocului disponibil.

Pentru a realiza o comandă, utilizatorul trebuie să specifice date precum tipul de flori, culoarea, cantitatea, accesorii (opțional), cutia (în cazul aranjamentelor) și hârtia de împachetat (pentru buchete). Fiecare comandă este validată înainte de a fi acceptată, iar dacă nu există stoc suficient sau datele sunt incorecte, aplicația notifică utilizatorul printr-un sistem de excepții. Comenzile plasate se înregistrează într-un istoric și pot fi vizualizate ulterior, împreună cu detalii precum data comenzii, clientul și prețul total.

# Descrierea îndeplinirii cerințelor în cod 

## Separare în fișiere
Toate clasele sunt separate în fișiere `.h` și `.cpp`. Nu se folosește `using namespace std`, ci se preferă utilizarea explicită a `std::`.

## Ierarhie cu moștenire
Clasa abstractă `Floare` este baza ierarhiei. Din ea derivă:
- `FloareSimpla`
- `BuchetSimplu`
- `BuchetPremium`
- `AranjamentFloral`

## Funcții virtuale pure
`pretTotal()` și `descriere()` sunt definite în `Floare` și suprascrise specific în fiecare derivată.

## Pointeri polimorfi
Clasa `Comanda` conține `std::shared_ptr<Floare>` și apelează metodele virtuale prin acest pointer. Acestea NU sunt folosite doar în `main`.

## Constructori care apelează baza
Toate clasele derivate apelează explicit constructorul clasei `Floare`.

## Copiere sigură + smart pointers
Se folosește `shared_ptr`, iar copierea obiectelor (ex. `Comanda`) respectă paradigma copy-and-swap.

## Downcasting cu `dynamic_cast`
Se utilizează `std::dynamic_pointer_cast` pentru identificarea tipului concret al unui `Floare` dintr-o comandă (ex: pentru afișări specifice).

## Excepții proprii
Există o ierarhie de excepții:
- Bază: `EroareAplicatie` (derivă din `std::exception`)
- Derivate: `EroareInputInvalid`, `EroareStocInsuficient`, `EroareFisier`

Acestea sunt aruncate la citire fișier, procesare comandă sau verificare stoc.

## Funcții și atribute statice
Pot fi folosite pentru a contoriza comenzile sau bugetul (ex: în `Comanda`).

## STL
Se utilizează `std::vector`, `std::map`, `std::string`, `std::sort` pentru manipularea datelor din stocuri și comenzi.

## Funcții de nivel înalt
Logica aplicației este organizată în metode precum `creeazaComanda()`, `afiseazaStoc()`, `adaugaProdus()`. `main()` doar apelează aceste funcții, fără detalii de implementare low-level.

### 📚 Bibliografie

1. [https://github.com/mcmarius/poo](https://github.com/mcmarius/poo)  
2. [https://github.com/DimaOanaTeodora/Tutoriat-POO-2022](https://github.com/DimaOanaTeodora/Tutoriat-POO-2022)  
3. [https://github.com/danielw98/Info-POO-Laborator-2023-2024-sem2](https://github.com/danielw98/Info-POO-Laborator-2023-2024-sem2)  
4. [https://www.w3schools.com/cpp/cpp_oop.asp](https://www.w3schools.com/cpp/cpp_oop.asp)
