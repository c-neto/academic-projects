# onLight - Casa Inteligente Arduino :house:

TCC em Redes de Computadores pela Etec Cônego José Bento (Jacareí)

Colaborades:

- [@bryan-lima](https://github.com/bryan-lima)
- [@JDanrley](https://github.com/JDanrley)

## Sobre:

O presente projeto demonstra um protótipo funcional de uma automação residencial usando umaplaca microcontroladora Arduino Uno, servo motor e LED’s em uma maquete de residência feito em madeirite, acedendo e apagando luzes, abrindo e fechando o portão, e que pode ser gerenciado através de uma página HTML, ou pelo aplicativo OnLight, desenvolvido para este fim, de forma local ou através de acesso remoto.

## Tecnologias utilizadas

Além das citadas abaixo, também foi usado o noIp para o serviço de DDNS, GIMP e Inkscape para edição e criação do layout do aplicativo  

![description](Imagens/Tabelas/materiais.jpg)

## Projeto em Funcionamento

Você pode ver o projeto em funcionamento clicando [neste link](https://youtu.be/56V8g1gVlg8)

## **Estrutura Física do projeto**

![description](Imagens/Casa/casa.png)

## Aplicativo

### **Tela Inicial do Aplicativo**

Tela que introduz o usuário ao aplicativo;

![hello](Imagens/apk/01.png)

### **Menu Principal**

Tela que expõem as funcionalidades do aplicativo;

![gps](Imagens/apk/02.jpg)

### **Opção: Controle Manual**

Ao clicar no ícone *Controle Manual*, o aplicativo irá expor os os cômodos da casa pelo qual deseja acender ou apagar a lâmpada ou abrir e fechar o portão da casa.

 ![gps](Imagens/apk/04.png)

### **Opção: Comando por Voz**

Ao clicar no ícone *Comando por Voz*, o aplicativo irá habilitar o microfone do smartphone para reconhecer o comando.

![gps](Imagens/apk/03.png)

### **Opção: Acesso Local**

Ao clicar no ícone *Acesso Local*, o aplicativo funcionará em abrângencia geográfica limitada ao alcance do aceess point de roteador da rede

![gps](Imagens/apk/offline.jpeg)

### **Opção: Acesso Via Internet**

Ao clicar no ícone *Acesso Via Internet*, o aplicativo funcionará em abrângencia geográfica mundial, desde que o dispositivo tenha acesso a Internet

![gps](Imagens/apk/online.jpeg)

### Topologias do Projeto:

## **Infraestrutura**

Detalhamento da Infraestrutura do Projeto

![description](Imagens/Topologia/redes.png)

## **Conexões do Arduino**

Esquema de pinagem do Arduino:

![description](Imagens/Topologia/arduino.png)
