#include <iostream>
#include <vector>
class Bursa{
private:
    float media;
    std::string localitatea_locuintei;
    std::string starea_de_sanatate;
    std::string situatia_parentala;
public:
    Bursa() {}
    Bursa(float media, const std::string &localitatea_locuintei, const std::string &starea_de_sanatate, const std::string &situatia_parentala){
        this->media = media;
        this->localitatea_locuintei = localitatea_locuintei;
        this->starea_de_sanatate = starea_de_sanatate;
        this->situatia_parentala = situatia_parentala;
    }//constructor

    Bursa(const Bursa &copie){
        this->media = copie.media;
        this->localitatea_locuintei = copie.localitatea_locuintei;
        this->starea_de_sanatate = copie.starea_de_sanatate;
        this->situatia_parentala = copie.situatia_parentala;
    }//constructor de copiere

    Bursa &operator=(const Bursa &copie){
        this->media = copie.media;
        this->localitatea_locuintei = copie.localitatea_locuintei;
        this->starea_de_sanatate = copie.starea_de_sanatate;
        this->situatia_parentala = copie.situatia_parentala;
        return *this;
    }// operatorul =

    friend std::ostream &operator<<(std::ostream &os, const Bursa &bursa) {
        os << " Media elevului este " << bursa.media << std::endl;
        os << " Localitatea locuintei elevului este " << bursa.localitatea_locuintei << std::endl;
        os << " Starea de sanatate a elevului este " << bursa.starea_de_sanatate << std::endl;
        os << " Elevul este crescut de " << bursa.situatia_parentala << std::endl;
        if(bursa.media >= 9 and (bursa.localitatea_locuintei != "Bucuresti" or bursa.situatia_parentala != "2 parinti" or bursa.starea_de_sanatate != "Sanatos"))
            os << " Bursa elevului este de 500 de lei" << std::endl;
        else
        if (bursa.media >= 9)
            os << " Bursa elevului este de 200 de lei" << std::endl;
        else
        if(bursa.localitatea_locuintei!="Bucuresti" or bursa.situatia_parentala!="2 parinti" or bursa.starea_de_sanatate!="Sanatos")
            os << " Bursa elevului este de 300 de lei" << std::endl;
        else os << " Bursa elevului este de 0 lei" << std::endl;
        return os;
    }// operatorul de afisare
};

class Elev{
private:
    int varsta;
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string sex;
    std::string clasa;
    std::vector<Bursa> bursa;
public:
    Elev(){}
    Elev(int varsta, const std::string &nume, const std::string &prenume, const std::string &cnp, const std::string &sex, const std::string &clasa){
        this->varsta = varsta;
        this->nume = nume;
        this->prenume = prenume;
        this->cnp = cnp;
        this->sex = sex;
        this->clasa = clasa;
    }//constructor
    virtual ~Elev() {
        std::cout<<"destructor"<<std::endl;
    }

    void combina(Bursa const &Bursa) {
        bursa.push_back(Bursa);
    }

    Elev(const Elev &copie){
        this->varsta = copie.varsta;
        this->nume = copie.nume;
        this->prenume = copie.prenume;
        this->cnp = copie.cnp;
        this->sex = copie.sex;
        this->clasa = copie.clasa;
    }//constructor de copiere

    Elev &operator=(const Elev &copie){
        this->varsta = copie.varsta;
        this->nume = copie.nume;
        this->prenume = copie.prenume;
        this->cnp = copie.cnp;
        this->sex = copie.sex;
        this->clasa = copie.clasa;
        return *this;
    }//operatorul =

    friend std::ostream &operator<<(std::ostream &os, const Elev &elev) {
        os << "Varsta elevului este " << elev.varsta << std::endl;
        os << " Numele elevului este " << elev.nume << std::endl;
        os << " Prenumele elevului este " << elev.prenume << std::endl;
        os << " Cnp-ul elevului este " << elev.cnp << std::endl;
        os << " Sexul elevului este " << elev.sex << std::endl;
        os << " Clasa elevului este " << elev.clasa << std::endl;
        for(const auto &bursa : elev.bursa)
            os << bursa;
        return os;
    }

};

class Liceu{
private:
    int nr_elevi;
    int nr_elev;
    std::string nume_complet_elevi;
    std::vector<Elev> elev;
public:
    Liceu() {}
    Liceu(int nr_elevi, int nr_elev, std::string const nume_complet_elevi){
        this->elev=elev;
        this->nr_elevi=nr_elevi;
        this->nr_elev=nr_elev;
    }

    void combina(Elev const &Elev) {
        elev.push_back(Elev);
    }

    Liceu(const Liceu &copie){
        this->nr_elevi = copie.nr_elevi;
        this->nume_complet_elevi = copie.nume_complet_elevi;
        this->nr_elev= nr_elev;
    }//constructor de copiere

    Liceu &operator=(const Liceu &copie){
        this->nr_elevi = copie.nr_elevi;
        this->nume_complet_elevi = copie.nume_complet_elevi;
        this->nr_elev= nr_elev;
        return *this;
    }//operatorul =

    friend std::ostream &operator<<(std::ostream &os, const Liceu &liceu) {
        os << "Numarul totali de elevi este " << liceu.nr_elevi << " dintre care " << liceu.nume_complet_elevi << " este elevul cu numarul "<< liceu.nr_elev<<std::endl;
        for(const auto &elev : liceu.elev)
            os << elev;

        return os;
    }
};

void afisare(Elev e, Bursa b){
    std::cout<<e<<std::endl<<b<<std::endl;
}
void afisl(Liceu L){
    std::cout<<L<<std::endl;
}

int main()
{
    Liceu L(119, 46, "Anastasia Elena");
    Elev e1 (17, "Anastasia", "Elena", "50456546812350", "feminin", "11C");
    Bursa b1 (8.5, "Bucuresti", "Sanatos", "2 parinti");
    e1.combina(b1);
    L.combina(e1);
    afisl(L);
    afisare(e1,b1);
}