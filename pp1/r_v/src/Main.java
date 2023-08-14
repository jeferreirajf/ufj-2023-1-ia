package logicafuzzy.ia;

import javax.swing.JOptionPane;

public class Main {
  
//Discentes:
//  202100912
//  201902027

//Tema: Advinhação de carreira

 public static void main(String[] args) {
     
     double MaiorGrauPertinencia;
     String NomeArea;

    
     
        //Cada Carreira possui um nivel de pertinencia a cada área, portanto a nossa função de pertinencia seria a
        DesignerGrafico dgraf = new DesignerGrafico(0.05, 0.3, 0.15, 0.3, 0, 0.2, 0);
        Escritor escritor = new Escritor(0.1, 0, 0.2, 0.4, 0.3, 0, 0);
        Programador prog = new Programador(0.3, 0.3, 0.1, 0.05, 0.05, 0.2, 0);
        EngenheiroCivil engciv = new EngenheiroCivil(0.2, 0.1, 0.2, 0.2, 0.1, 0.2, 0);
                                               
        Questionario questionario =  new Questionario(  Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Logica (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Tecnologia (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Comunicacao (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Criatividade (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Humanas (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Exatas (0 a 10): ")),
                                                        Double.parseDouble(JOptionPane.showInputDialog("Sua Nota para Biologicas (0 a 10): ")) 
        );
        
        
       MaiorGrauPertinencia = questionario.Similiaridade(dgraf);
       NomeArea="Designer Grafico";
       if(questionario.Similiaridade(escritor)> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(escritor);
           NomeArea ="Escritor";
       }
       if(questionario.Similiaridade(engciv)> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(engciv);
           NomeArea ="Engenharia Civil";
       }
       if(questionario.Similiaridade(prog)> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(prog) ;
           NomeArea ="Programador";
       }
       
       
       MaiorGrauPertinencia = questionario.Similiaridade(dgraf.getLogica(), dgraf.getTecnologia() ,dgraf.getComunicacao(), dgraf.getCriatividade(), dgraf.getHumanas(), dgraf.getAxatas(), dgraf.getBiologicas());
       NomeArea="Designer Grafico";
       if(questionario.Similiaridade(escritor.getLogica(), escritor.getTecnologia() ,escritor.getComunicacao(), escritor.getCriatividade(), escritor.getHumanas(), escritor.getAxatas(), escritor.getBiologicas())> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(escritor);
           NomeArea ="Escritor";
       }
       if(questionario.Similiaridade(engciv)> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(engciv);
           NomeArea ="Engenharia Civil";
       }
       if(questionario.Similiaridade(prog)> MaiorGrauPertinencia){
           MaiorGrauPertinencia = questionario.Similiaridade(prog) ;
           NomeArea ="Programador";
       }
        
        JOptionPane.showMessageDialog(null,"Seu maior grau de pertinencia é : "+MaiorGrauPertinencia+"\nNa área"+NomeArea); 
        
        
 }
    
}
