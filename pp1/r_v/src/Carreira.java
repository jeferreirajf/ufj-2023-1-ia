package logicafuzzy.ia;
//Discentes:
//  Ryan
//  Verônica

//Tema: Recomendação de carreira
//

public abstract class Carreira {

   

    public Carreira(double logica, double tecnologia, double comunicacao, double criatividade, double humanas, double axatas, double biologicas) {
        this.logica = logica;
        this.tecnologia = tecnologia;
        this.comunicacao = comunicacao;
        this.criatividade = criatividade;
        this.humanas = humanas;
        this.axatas = axatas;
        this.biologicas = biologicas;
    }
 
    
    //Abaixo estão as Caracteristicas Fuzzy
    private double logica;
    private double tecnologia;
    private double comunicacao;
    private double criatividade;
    private double humanas;
    private double axatas;
    private double biologicas;

    public double getLogica() {
        return logica;
    }

    public void setLogica(double logica) {
        this.logica = logica;
    }

    public double getTecnologia() {
        return tecnologia;
    }

    public void setTecnologia(double tecnologia) {
        this.tecnologia = tecnologia;
    }

    public double getComunicacao() {
        return comunicacao;
    }

    public void setComunicacao(double comunicacao) {
        this.comunicacao = comunicacao;
    }

    public double getCriatividade() {
        return criatividade;
    }

    public void setCriatividade(double criatividade) {
        this.criatividade = criatividade;
    }

    public double getHumanas() {
        return humanas;
    }

    public void setHumanas(double humanas) {
        this.humanas = humanas;
    }

    public double getAxatas() {
        return axatas;
    }

    public void setAxatas(double axatas) {
        this.axatas = axatas;
    }

    public double getBiologicas() {
        return biologicas;
    }

    public void setBiologicas(double biologicas) {
        this.biologicas = biologicas;
    }

//Esta é a função de inferencia que de acordo com os dados fornecidos do usuario
//que por meio de média ponderada retorna um valor equivalente ao grau de inferencia do usuario a profissão
    public double Similiaridade(Carreira usuario){
        return  (getAxatas()*usuario.getAxatas()+
                getBiologicas()*usuario.getBiologicas()+
                getComunicacao()*usuario.getComunicacao()+
                getCriatividade()*usuario.getCriatividade()+
                getHumanas()*usuario.getHumanas()+
                getLogica()*usuario.getLogica()+
                getTecnologia()*usuario.getTecnologia()
                );
    }
     public double Similiaridade(double logica, double tecnologia, double comunicacao, double criatividade, double humanas, double axatas, double biologicas){
        return  (getAxatas()*axatas+
                getBiologicas()*biologicas+
                getComunicacao()*comunicacao+
                getCriatividade()*criatividade+
                getHumanas()*humanas+
                getLogica()*logica+
                getTecnologia()*tecnologia);
    }

    @Override
    public String toString() {
        return "Carreira{" + "logica=" + logica + ", tecnologia=" + tecnologia + ", comunicacao=" + comunicacao + ", criatividade=" + criatividade + ", humanas=" + humanas + ", axatas=" + axatas + ", biologicas=" + biologicas + '}';
    }

     
    
    
    
}