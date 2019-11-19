/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE
 *  Nombre: Alexander Yaguachi 
 *  Valide la cédula ecuatoriana que se ingresa por comunicación serial con el Formato. 172007541-3 
 */
 //Validación de la cédula:
 
 String cedula;// Dato que se recibe por serial
 int tam=0;//Variable para determinar el tamaño de Cedula
 int i=0;// Variable de conteo o recorrido
 char dato;
 int ent;// variable para valores enteros
 int dec=0,decM=0,pm=0; 
 int com=1;
 void setup() 
 {
  Serial.begin(9600);                  //comunicación serial
  Serial.println("Ingrese la Cedula"); // Se ingresa la cedula para luego verificar la validacion de la cedula mismo.
  }

void loop() {
  if(Serial.available()>0){        //dato a procesar 
    cedula=Serial.readString();    //cedula ingresada
    tam=cedula.length();           //tamaño del string
    char vector[tam];              //declaramos un vector donde se almacenan en las variables
    cedula.toCharArray(vector,tam+1);
    if(tam==11){
      if (vector[9]=='-'){        // Verifica la posición 9 del vector que presente un guión
        i=0;
        for (; i < 9; i++) {      // verifica el valor de uno por uno
        dato = vector[i];//
           ent=String(dato).toInt();    // valor a entero
           if (isDigit(dato)) {         // verifica que los datos ingresados son números
           if(vector[2]=='0'||vector[2]=='1'||vector[2]=='2'||vector[2]=='3'||vector[2]=='4'||vector[2]=='5'){
           if(vector[0]=='0'||vector[0]=='1'||vector[0]=='2'){
           if(String(vector[0]).toInt()==2){
           if(String(vector[1]).toInt()<5){
                    
          //Validación último digito
           if (i % 2 == 0) {     //se establece para números pares condición de modulo
            pm=0;                //reseteo variable de almacenamiento
            if (ent*2>10) {      //si el resultado de la multiplicación es mayor a 10
              pm = pm+ent*2-9; 
            } else { 
              pm = pm+2*ent;     //se mantiene igual
            }   
            }else { 
            pm = pm + ent;
          }
           
           }
            else {
            Serial.println("Cedula ingresada es incorrecta primeros digitos "); 
            break;                                                                                       
           }
           }
           else{
             Serial.println("Cedula ingresada es incorrecta debe tener guion"); 
             break;
           }
           }
           else {
            Serial.println("Cedula ingresada es incorrecta no tiene 11 carácteres"); 
             break;
           }
            
          }else{
            Serial.println("Cedula ingresada es incorrecta no tiene que tener letras");
             break; 
          }
          
          }
        
           if (tam==11) { //Si cumple
          dec=pm/10; 
          decM=(dec+1)*10-pm; 
         dato= vector [10]; 
            if (decM==atoi(&dato)) {
               
            Serial.println("Cedula ingresada Correcta");  //
              } 
            } 
          }
         }
       }
     }
   }
