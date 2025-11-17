\section{UltraTSummit}

\textbf{Última atualização: 16/11/2025, para a Summit 2025.}

\section{Mini Sumo Auto/RC Ultra T}

Ultra T é um robô desenvolvido pela Equipe de Robótica da \textbf{UERJBotz} em 2023. Seu design foi inspirado no personagem fictício de mesmo nome.

\begin{figure}[H]
    \centering
    \includegraphics[width=0.9\textwidth]{https://github.com/user-attachments/assets/ad887140-48a0-4c51-8952-10f8e7772970}
    \caption{Desenho técnico.}
\end{figure}

% --------------------------------------------------------------

\section{Sensores}

Ultra T possui um total de quatro sensores, sendo dois frontais e dois laterais.  
Devido às regras da categoria de mini sumô, o robô deve pesar no máximo 500~g e ter dimensões máximas de \(10\,\text{cm} \times 10\,\text{cm}\), fatores que influenciam diretamente na disposição da eletrônica.

\subsection*{Pinagem no código:}
\begin{quote}
Sensor Lateral Esquerdo: pino 35\\
Sensor Frontal Esquerdo: pino 33\\
Sensor Frontal Direito: pino 14\\
Sensor Lateral Direito: pino 34
\end{quote}

\subsection*{Características:}
\begin{itemize}
    \item Alcance de detecção: 40~cm
    \item Dimensões: \(17{,}7\,\text{mm} \times 11{,}5\,\text{mm} \times 12{,}6\,\text{mm}\)
    \item Fios:
        \begin{itemize}
            \item \textbf{Preto}: Sinal digital (0 = 0~V = sem obstáculo / 1 = 5~V = obstáculo detectado)
            \item \textbf{Marrom}: Alimentação 5~V
            \item \textbf{Azul}: GND
        \end{itemize}
\end{itemize}

\begin{figure}[H]
    \centering
    \includegraphics[width=0.35\textwidth]{https://github.com/user-attachments/assets/99f5d452-e4a5-4368-93ab-6d7e7bb192d1}
    \caption{Sensor JSumo.}
\end{figure}

% --------------------------------------------------------------

\section{Sensor Receptor IR}

Há também um receptor infravermelho para o modo autônomo, permitindo que o robô receba comandos provenientes do juiz.

\begin{figure}[H]
    \centering
    \includegraphics[width=0.35\textwidth]{https://github.com/user-attachments/assets/2eb800f3-2c23-4c45-bf8f-d138ca266f0e}
    \caption{Receptor IR VS1838B.}
\end{figure}

% --------------------------------------------------------------

\section{Placa Eletrônica}

A placa foi projetada e desenvolvida no \textit{EasyEDA}, utilizando como controlador o \textbf{ESP32} e duas pontes H \textbf{DRV8833}.

\begin{figure}[H]
    \centering
    \includegraphics[width=0.5\textwidth]{https://github.com/user-attachments/assets/ca5fbf65-0934-4d7f-98d1-76e312d2447a}
    \caption{Placa eletrônica desenvolvida para mini sumô.}
\end{figure}

\begin{figure}[H]
    \centering
    \includegraphics[width=0.5\textwidth]{https://github.com/user-attachments/assets/bcabcb4d-5d36-4fa3-80d5-55d7ac197249}
    \caption{Placa com pinagem.}
\end{figure}

\begin{figure}[H]
    \centering
    \includegraphics[width=0.5\textwidth]{https://github.com/user-attachments/assets/413e08a6-89bb-4d18-8af3-694319948d8f}
    \caption{Pinagem detalhada.}
\end{figure}

% --------------------------------------------------------------

\section{ESP32}

O controlador escolhido foi o \textbf{ESP32} devido à sua dimensão reduzida, maior capacidade de processamento e maior quantidade de recursos, incluindo canais PWM.

\begin{figure}[H]
    \centering
    \includegraphics[width=0.35\textwidth]{https://github.com/user-attachments/assets/99d41dac-efae-4d13-92c0-32b5b8d3c3d4}
    \caption{Placa ESP32.}
\end{figure}

% --------------------------------------------------------------

\section{DRV8833}

A ponte H DRV8833 possui tamanho reduzido em comparação a outras soluções disponíveis no mercado e suporta correntes elevadas para baterias de até 16{,}8~V.

\begin{quote}
Recomenda-se testar os pinos dos motores sempre que houver manutenção nos atuadores. É aconselhado rodar um programa de teste para verificar o sentido de rotação e, se necessário, reconfigurar a pinagem no código.  
Pinos definidos na placa:  
Motor esquerdo --- pinos 18 e 19\\
Motor direito --- pinos 4 e 23
\end{quote}

\begin{figure}[H]
    \centering
    \includegraphics[width=0.6\textwidth]{https://github.com/user-attachments/assets/99019e53-a489-4d2f-bde0-24088f7c3eab}
    \caption{Ponte H DRV8833.}
\end{figure}

