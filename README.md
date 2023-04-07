# AutoAgro
Um Robô Automático Aplicado Em Plantações e Hortas

![GitHub repo size](https://img.shields.io/github/repo-size/iuricode/README-template?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/iuricode/README-template?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/iuricode/README-template?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/iuricode/README-template?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/iuricode/README-template?style=for-the-badge)

<img src="project-image.jpg" alt="exemplo imagem">

> Um Robô Automático Aplicado Em Plantações e Hortas. Essa é uma solução barata e simples, não só para usar em hortas e jardins da população geral, como em pequenos sistemas agricolas.

### Progresso de Desenvolvimento

O projeto ainda está em desenvolvimento e as próximas atualizações serão voltadas nas seguintes tarefas:

- [x] Fazer Motores Funcionarem
- [ ] Controlar Robô Remotamente
- [ ] Design de Estrutura Nova em 3d
- [ ] Impressão em Impressora 3d
- [ ] Sistema de Regador
- [ ] Extras...
- [ ] Teste de Campo

### Diário de Bordo
- 31/03/2023 -> O PROTÓTIPO FOI MONTADO E OS MOTORES FUNCIONARAM AO SEREM CONTROLADOS PELA WEMOS, USANDO UMA PONTE-H L298N 
  - **OBS:** A PONTE SÓ SUPORTA DOIS MOTORES, ENTÃO JUNTAMOS OS FIOS DE 2 MOTORES, EM 1 UNICO FIO, GERANDO MENOS DESEMPENHO 
    - BUSCAR PONTE H NOVA
  - **OBS:** FOI USADO UMA BATERIA 9V PARA ALIMENTAR A PONTE H E O ARDUINO, PODENDO DANIFICAR A PLACA 
    - BUSCAR FONTE 5V EXCLUSIVA PARA O ARDUINO
- 04/04/2023 -> CONTROLE REMOTO DE MOTORES USANDO UDP(HTTP)
  - **OBS:** UDP PRODUZ GRANDE PERDA DE INFORMAÇÃO NA HORA DA COMUNICAÇÃO, MAS OBTEM MELHOR VELOCIDADE
  - **OBS:** EM TESTES O USO DE TCP, EVITA PERDA DE INFORMAÇÃO, MAS É MUITO LENTA
  - **OBS**: BUSCAR APLICAR MQTT, PARA EVITAR PERDA DE PACOTES E OBTER MELHOR VELOCIDADE

### Estrutura
- WeMos D1 R2(BASEADA EM Esp8266)
  - Controla o Circuito do Robô
  - Placa Mais Barata, Mais Potente e com WIFI Integrado
- Ponte H 
  - Para Controlar a Alimentação dos Motores
- 4 Motores 5v
  - PARA TRANSFORMAR ENERGIA ELETRICA EM CINETICA, OU SEJA, MOVER AS RODAS
- Bateria 9v
  - Alimentação da Ponte H e Arduino

## 🤝 Colaboradores

Conheça a Equipe que Desenvolve o Projeto:

<table>
  <tr>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/70450809?v=4" width="100px;" alt="Foto do André Luís no GitHub"/><br>
        <sub>
          <b>André Luís</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/22924376?v=4" width="100px;" alt="Foto do Guilherme Daniel no GitHub"/><br>
        <sub>
          <b>Guilherme Daniel</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/96800134?v=4" width="100px;" alt="Foto do Davyd Lucas no GitHub"/><br>
        <sub>
          <b>Davyd Lucas</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/129461553?v=4" width="100px;" alt="Foto do Diego no GitHub"/><br>
        <sub>
          <b>Diego</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/101540115?v=4" width="100px;" alt="Foto do Arthur P. Barradas no GitHub"/><br>
        <sub>
          <b>Arthur P. Barradas</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

## 📝 Licença

Esse projeto está sob licença. Veja o arquivo [LICENÇA](LICENSE) para mais detalhes.

[⬆ Voltar ao topo](#nome-do-projeto)<br>
