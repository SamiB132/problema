using namespace std;

struct nod{
    float nr;
    nod *urm;
};

void citire(nod* &prim,nod* &ultim, int x)
{
    if(ultim==NULL)
    {
        nod*p=new nod;
        p->nr=x;
        p->urm=NULL;
        prim=p;
        ultim=p;
    }
    else
    {
        nod *p=new nod;
        p->nr=x;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;
    }
}

void afisare(nod *prim)
{
    cout<<endl;
    while (prim!=NULL)
    {
        cout<<prim->nr<<" ";
        prim=prim->urm;
    }
    cout<<endl;
}

void adaug_dupa_ultim(nod* &ultim)
{
    cout<<"\nCe element va fi adaugat?\n";
    float x;
    cin>>x;

    nod *q;
    q=new nod;
    q->nr=x;
    q->urm=NULL;
    ultim->urm=q;
    ultim=q;
}

void adaug_inainte_de_prim(nod* &prim)
{
    cout<<"\nCe element va fi adaugat?\n";
    float x;
    cin>>x;
    nod *p;
    p=new nod;
    p->nr=x;
    p->urm=prim;
    prim=p;
}

void adaug_dupa_element(nod *prim)
{
    int v;
    cout<<"\nDupa care element din lista se va adauga noul element?\n";
    cin>>v;

    nod *p;
    nod *q;
    nod *aux;

    bool exista=false;

    for(p=prim;p!=NULL;p=p->urm)
    {
        if(p->nr==v)
        {
            exista=true;
            break;
        }
    }
    if(exista)
    {
        float x;
        cout<<"\n\nCe element va fi adaugat?\n";
        cin>>x;
        aux=new nod;
        q=p->urm;
        aux->nr=x;
        p->urm=aux;
        aux->urm=q;
    }
    else if(prim==NULL) cout<<"\nLista este vida!";
    else cout<<"\nElementul "<<v<<" nu se afla in lista!";
}

void cautare_pozitie(nod *prim)
{
    cout<<"\n\nPe ce pozitie se afla elementul care trebuie cautat?\n";
    int poz;
    cin>>poz;

    nod *p=prim;

    int i=1;
    while(i!=poz)
    {
        p=p->urm;
        i++;
    }

    cout<<"\nElementul de pe pozitia "<<poz<<" este: "<<p->nr;
}

void cautare_valoare(nod *prim)
{
    cout<<"\n\nCe element se cauta?\n";
    float nrx;
    cin>>nrx;

    bool exista=false;

    unsigned poz=0;

    for(nod *p=prim; p!=NULL;p=p->urm)
    {
        if(p->nr==nrx)
        {
            exista=true;
            poz++;
            break;
        }
        else poz++;
    }

    if(exista) cout<<"\n\nElementul "<<nrx<<" se afla pe pozitia "<<poz;
    else cout<<"\n\nElementul "<<nrx<<" nu se afla in lista";
}

void stergere_pozitie(nod* &prim)
{
    cout<<"\n\nDe pe ce pozitie se va sterge elementul:";
    int poz;
    cin>>poz;

    if(poz==1)
    {
        nod *p=prim;
        prim=prim->urm;
        delete p;
    }
    else
    {
        nod *q;
        nod *p;
        nod *aux;

        int i=2;
        for(p=prim; p!=NULL; p=p->urm)
        {
            if(i==poz)
            {
                q=p->urm;
                aux=q->urm;
                delete q;
                p->urm=aux;
                break;
            }
            i++;
        }
    }
}

void stergere_valoare(nod* &prim)
{
    cout<<"\n\nCe valoare va fi stearsa?\n";
    float nrx;
    cin>>nrx;

    bool exista = false;
    for(nod *p=prim; p!=NULL; p=p->urm)
    {
        if(p->urm->nr==nrx)
        {
            exista=true;
            nod *q;
            q=p->urm;
            nod *aux;
            aux=q->urm;
            delete q;
            p->urm=aux;
        }
    }

    if(!exista) cout<<"\nElementul nu exista in lista.";
}
