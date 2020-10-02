package tabela;
//import java.util.Vector;
//import java.util.Arrays;

public class Time {
    //Atributos
    private final Jogador[] jogadores;
    private final Comissao[] tecnicos;
    private int indice1 = 0;
    private final int indice2 = 0;
    //private Vector<Jogador> jogadores;
    //private Vector<Comissao> tecnicos;
    private String nome;
    private int titulosT;
    private int vitorias;
    private int derrotas;
    private int pontos;
    private int golsM;
    private int golsS;
    private int Sdg;
    private int numpartida;
    
    //Pessoa a = new Jogador("maycon", "brasileiro", 20, 1, 64, 0, true , "Goleiro", "vasco");
    
    //Metodos Publicos
    public void status(){
        System.out.println("#################################################");
        System.out.println("Nome : " +this.getNome());
        System.out.println("Pontos : " + this.getPontos());
        System.out.println("Gols Marcados : " + this.getGolsM());
        System.out.println("Gols Sofridos : " + this.getGolsS());
        System.out.println("Saldo de gols : " + this.getSdg());
        System.out.println("Numero de vitorias : " + this.getVitorias());
        System.out.println("Numero de derrotas : " + this.getDerrotas());
        System.out.println("Numero de partidas : " + this.getNumpartida());
        System.out.println("Titulos : " + this.getTitulosT());
    }
    
    
    public void numMaxPartida(){
        this.setNumpartida(this.getNumpartida() + 1);
    }
    public void adiciJogador(Jogador jogador){
        jogadores[indice1] = jogador;
        indice1++;
        //jogadores.add(jogador);
    }
    /*public void adiciComissao(Comissao tecnico){
        tecnicos.add(tecnico);
    }*/
    public Jogador procurar(String nome){
    for(Jogador jogador : jogadores) {
      if(jogador.getNome().equals(nome)) {
        return jogador;
      }
    }
        return null;
    } 
    public void timeCampeao(){
        this.setTitulosT(this.getTitulosT() + 1);
    }    
    public void saldoGosls(){
        this.setSdg(this.getGolsM() - this.getGolsS());
    }
    //Metodos Especiais

    //public Time(String nome, int titulosT, int vitorias, int derrotas, int pontos, int golsM, int golsS) {
    public Time(String nome) {
        jogadores = new Jogador[5];
        //jogadores = new Vector<Jogador>();
        tecnicos = new Comissao[2];
        //tecnicos = new Vector<Comissao>();
        this.nome = nome;
        this.titulosT = 0;
        this.vitorias = 0;
        this.derrotas = 0;
        this.pontos = 0;
        this.golsM = 0;
        this.golsS = 0;
    }

    public int getNumpartida() {
        return numpartida;
    }

    public void setNumpartida(int numpartida) {
        this.numpartida = numpartida;
    }
    
    public int getSdg() {
        return Sdg;
    }

    public void setSdg(int Sdg) {
        this.Sdg = Sdg;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getTitulosT() {
        return titulosT;
    }

    public void setTitulosT(int titulosT) {
        this.titulosT = titulosT;
    }

    public int getVitorias() {
        return vitorias;
    }

    public void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }

    public int getDerrotas() {
        return derrotas;
    }

    public void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }

    public int getPontos() {
        return pontos;
    }

    public void setPontos(int pontos) {
        this.pontos = pontos;
    }

    public int getGolsM() {
        return golsM;
    }

    public void setGolsM(int golsM) {
        this.golsM = golsM;
    }

    public int getGolsS() {
        return golsS;
    }

    public void setGolsS(int golsS) {
        this.golsS = golsS;
    }
    
    
}

