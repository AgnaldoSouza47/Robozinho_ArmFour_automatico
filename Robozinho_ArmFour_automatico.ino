/* Automação do robozinho armfour
 sexta_feira  03/06/2022 
 Fonte de inspiração
 Wrkits armfive*/

#include <Servo.h>

// Definição de constantes
 #define servoGarra    8  
 #define servoCotovelo 6   
 #define servoOmbro    5   
 #define servoBase     3   

 // Funções para movimento suave dos servos motores

 void moveCotoveloCima(const int tempoespera, int inicio, int fim);        
 void moveCotoveloBaixo(const int tempoespera, int inicio, int fim);      
 void moveOmbroFrente(const int tempoespera, int inicio, int fim);   
 void moveOmbroTras(const int tempoespera, int inicio, int fim);    
 void moveBaseDireita(const int tempoespera, int inicio, int fim);       
 void moveBaseEsquerda(const int tempoespera, int inicio, int fim);        

 // Funções de Manipulação
 void GuinOrigin(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);
 void GuinOrigin2(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);
 void GuinDestino(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim);
 //    positionGuin(BASE INICIAL, BASE FINAL, OMBRO INICIAL, OMBRO FINAL, COTOVELO INICIAL, COTOVELO FINAL, PUNHO INICIAL, PUNHO FINAL);
  // Atribuição de objetos (servos do braço)
 Servo servo_Base, servo_Ombro, servo_Cotovelo,servo_Garra;
  
  void setup(){
  pinMode(servoGarra, OUTPUT);  
  pinMode(servoCotovelo, OUTPUT);
  pinMode(servoOmbro, OUTPUT);
  pinMode(servoBase, OUTPUT);
    
  servo_Garra.attach(8);
 
  servo_Cotovelo.attach(6);
  servo_Ombro.attach(5);
  servo_Base.attach(3);
  
  servo_Base.write(90);
  servo_Cotovelo.write(160);
  servo_Ombro.write(30);
 
  servo_Garra.write(60);  
  
  delay(3000);

 }//FIM DO SETUP

   void loop(){ 
 
 
    // OBJETO 01
  
  //        B  B   O  O      C  C     
 GuinOrigin(90,50, 30,100,  160,170 );  // Preencher Origem aqui (start parametros)
            // Coloque o segundo parametro após a virgula
 //                 G
  servo_Garra.write(2 ); // pega objeto,esses parametros poderão ser mudados
  delay(1000);
  
  //         B  B    O   O   C  C    
 GuinOrigin(50,90,  100,30, 170,160);         // Preencher Origem aqui (1ºs parametros)
 delay(1000);
 //          B   B    O  O     C   C   
 GuinOrigin2(90,170 , 30,30,  160,180 ); // Preencher Destino aqui (2ºs parametros)

  delay(1000);  //   G
  servo_Garra.write(60); // SOLTA
  
   delay(1000);//B B   O  O      C  C          // exemplo  B B (40,170) B B (170,40) FAZ A INVERSÃO
   GuinDestino(170,90, 30,30,  180,160  ); // Quando terminar um parametro inicia no outro
               //     G
   servo_Garra.write(60); //aberta
  
  delay(290);
  
      //END LOOP 1 
     //fim do objeto 1
    
  }
 void GuinOrigin(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim)
 {
  // Movimenta a base
 
    if(baseInicio < basefim)
    {
        moveBaseDireita(30,baseInicio,basefim);  //move a base para direita
        delay(100);
    }
    else
    {
       moveBaseEsquerda(30,baseInicio,basefim);//move a base para esquerda
        delay(100);
    }
  // Fim movimentação da base
  
 // Movimenta o cotovelo
    if(CotoveloInicio < Cotovelofim)
    {
        moveCotoveloCima(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
    else
    {
        moveCotoveloBaixo(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
  //Fim da  movimentação do cotovelo
  
  // Movimenta o ombro
    if(OmbroInicio < Ombrofim)
    {
        moveOmbroFrente(10,OmbroInicio,Ombrofim);
        delay(100);
    }
    else
    {
       moveOmbroTras(10,OmbroInicio,Ombrofim);
        delay(100);
    }
  // Fim da movimentação do ombro
      //Fim da movimentação 
}
 
 void GuinOrigin2(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim)
 {// Movimenta a base
    if(baseInicio < basefim)
    {
        moveBaseDireita(30,baseInicio,basefim);  //move a base para direita
        delay(100);
    }
    else
    {
       moveBaseEsquerda(30,baseInicio,basefim);//move a base para esquerda
        delay(100);
    }
  // Fim movimentação da base
  
   // Movimenta o cotovelo
    if(CotoveloInicio < Cotovelofim)
    {
        moveCotoveloCima(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
    else
    {
        moveCotoveloBaixo(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
  //Fim da  movimentação
  
  // Movimenta o ombro
    if(OmbroInicio < Ombrofim)
    {
        moveOmbroFrente(10,OmbroInicio,Ombrofim);
        delay(100);
    }
    else
    {
       moveOmbroTras(10,OmbroInicio,Ombrofim);
        delay(100);
    }
  // Fim da movimentação do ombro
                         
 } //Fim da movimentação guinOrigen2

  void GuinDestino(unsigned char baseInicio, unsigned char basefim, unsigned char OmbroInicio, unsigned char Ombrofim, unsigned char CotoveloInicio, unsigned char Cotovelofim )
 {// Movimenta a base
    if(baseInicio < basefim)
    {
        moveBaseDireita(30,baseInicio,basefim);  //move a base para direita
        delay(100);
    }
    else
    {
       moveBaseEsquerda(30,baseInicio,basefim);//move a base para esquerda
        delay(100);
    }
  // Fim movimentação da base
  
  // Movimenta o cotovelo
    if(CotoveloInicio < Cotovelofim)
    {
        moveCotoveloCima(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
    else
    {
        moveCotoveloBaixo(10,CotoveloInicio,Cotovelofim);
        delay(100);
    }
  //Fim da  movimentação do cotovelo
  
  // Movimenta o ombro
    if(OmbroInicio < Ombrofim)
    {
        moveOmbroFrente(10,OmbroInicio,Ombrofim);
        delay(100);
    }
    else
    {
       moveOmbroTras(10,OmbroInicio,Ombrofim);
        delay(100);
    }
  // Fim da movimentação do ombro
       
 
 } //Fim do GuinDestino

    //FIM DO LAÇO FOR
//FIM DO MOVE
 void moveCotoveloCima(const int tempoespera, int inicio, int fim)
 {
 //Tempo sugerido é de 10 ms(servos de auto torque
 for(int i=inicio; i<fim; i++)
    {
      servo_Cotovelo.write(i);
      delay(tempoespera);
    //Fim do movimento do cotovelo para cima ++
    }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 void moveCotoveloBaixo(const int tempoespera, int inicio, int fim)
 {
 for(int i=inicio; i>fim; i--)
    {
      servo_Cotovelo.write(i);
      delay(tempoespera);
     
 //Fim do movimento do cotovelo para baixo --
  }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 void moveOmbroFrente(const int tempoespera, int inicio, int fim)
 {
  for(int i=inicio; i<fim; i++)
    {
      servo_Ombro.write(i);
      delay(tempoespera);
   
 //Fim do movimento do ombro para frente ++
   }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 void moveOmbroTras(const int tempoespera, int inicio, int fim)
 {
 for(int i=inicio; i>fim; i--)
    {
      servo_Ombro.write(i);
      delay(tempoespera);
     //Fim do movimento do ombro para tras --
       }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 void moveBaseDireita(const int tempoespera, int inicio, int fim)
 {
 for(int i=inicio; i<fim; i++)
    {
      servo_Base.write(i);
      delay(tempoespera);
  
 //Fim do movimento da base para direita ++
  }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 void moveBaseEsquerda(const int tempoespera, int inicio, int fim)
 {
 for(int i=inicio; i>fim; i--)
    {
      servo_Base.write(i);
      delay(tempoespera);
  
 //Fim do movimento da base para esquerda--
  }//FIM DO LAÇO FOR
 }//FIM DO MOVE
 //FIM DA PROGRAMAÇÃO
