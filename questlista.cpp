package tabela;

public abstract class Pessoa{
    //Atributos
    String nome;
    String nacionalidade;
    String time;
    int idade;
    float altura;
    float peso;
    int titulos;
    boolean saude;
    abstract public void status();
    abstract public void ganharTitulos();
}

