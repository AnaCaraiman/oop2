## Obiective
Proiectul gestionează comenzile și stocurile unei florării: flori, accesorii și cutii.
Sunt folosite șabloane (template-uri) pentru a generaliza logica de gestiune a stocurilor și două design patterns pentru un cod mai flexibil și clar.

## Template-uri
Clasa `Depozit` a fost transformată într-o clasă șablon:
```cpp
template <typename T>
class Depozit {
    std::map<T, int> stocProduse;
    std::map<T, double> preturiProduse;
};
```
Această schimbare permite acum folosirea `Depozit` pentru:
- flori (`T = std::pair<std::string, std::string>`)
- accesorii (`T = std::pair<std::string, AccesoriuTag>`)
- cutii (`T = std::pair<std::string, CutieTag>`)

A fost adăugată și o funcție șablon generală care poate afișa orice colecție:
```cpp
template <typename T>
std::ostream& afiseazaColectie(std::ostream& os, const std::vector<T>& colectie) {
    for (const auto& elem : colectie)
        os << elem << "\n";
    return os;
}
```

Aceasta se folosește pentru afișarea comenzilor și a altor liste de produse.


## Design patterns
**Singleton**  
Clasa `Depozit` folosește Singleton pentru a exista o singură instanță pentru fiecare tip de stoc:
```cpp
static Depozit& getInstance() {
    static Depozit instance;
    return instance;
}
```
Astfel se evită duplicarea instanțelor și se asigură consistența datelor.

**Builder**  
Pentru gestionarea comenzilor a fost implementat `ComandaBuilder`.
Acesta permite crearea pas cu pas a unei comenzi, cu un cod mai clar:
```cpp
Comanda comanda = ComandaBuilder()
    .setClient(client)
    .setProdus(produs)
    .setDataOra(dataOra)
    .build();
```

---

### Respectarea principiilor SOLID

Proiectul respectă principiile SOLID astfel:

* **Single Responsibility Principle**: fiecare clasă are un scop clar (de exemplu, `Depozit` doar pentru stocuri, `Comanda` doar pentru comenzi).
* **Open/Closed Principle**: clasele pot fi extinse (de exemplu, prin template-uri și moștenire), dar nu trebuie modificate direct pentru funcționalități noi.
* **Liskov Substitution Principle**: clasele derivate (`BuchetSimplu`, `BuchetPremium`, `AranjamentFloral`) pot fi folosite în locul clasei de bază `Floare` fără probleme.
* **Interface Segregation Principle**: fiecare clasă folosește doar metodele de care are nevoie, fără a implementa metode inutile.
* **Dependency Inversion Principle**: clasele folosesc tipuri generice și abstractizări (ex. template-uri), nu depind direct de implementări concrete.

---


## Concluzie
Clasa Depozit a devenit un template, astfel încât să poată gestiona generic orice tip de produs.
Această modificare, împreună cu cele două design patterns (Singleton și Builder), asigură un cod clar, organizat și îndeplinește toate cerințele pentru un proiect flexibil și ușor de întreținut.
