package tabela;

public class Jogador extends Pessoa{
    //Atributos
    String posicao;
    //Metodos Publicos
    @Override
    public void status(){
        System.out.println("Nome:" +this.getNome());
        System.out.println("Nacionalidade: " +this.getNacionalidade());
        System.out.println("Posicao : " +this.getPosicao());
        System.out.println("Idade: " +this.getIdade());
        System.out.println("Titulos " +this.getTitulos());
        System.out.println("Saude: "+this.getSaude());
    }
    @Override
    public void ganharTitulos(){
        this.setTitulos(this.getTitulos() + 1);
    }
    //Metodos especiais

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }
    
    public String getPosicao() {
        return posicao;
    }

    public void setPosicao(String nome) {
        this.posicao = nome;
    }
    
    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public int getTitulos() {
        return titulos;
    }

    public void setTitulos(int titulos) {
        this.titulos = titulos;
    }

    public boolean getSaude() {
        return saude;
    }

    public void setSaude(boolean saude) {
        this.saude = saude;
    }
    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }
    
    public Jogador(String nome, String nacionalidade, int idade, float altura, float peso, int titulos, boolean saude, String posicao, String time) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
        this.idade = idade;
        this.altura = altura;
        this.peso = peso;
        this.titulos = titulos;
        this.saude = saude;
        this.posicao = posicao;
        this.time = time;
    }
    
}
