/*
 * Programacao Concorrente e Distribuida
 * Secao Critica - Exercicio 3
 * Helio Didzec Junior
 * Yasmin Beatriz Deodato
 */

import java.util.concurrent.Semaphore;
public class TrafficController {

    private Semaphore sem = new Semaphore(1, true);

    public void enterLeft() {
        obterPermissaoParaAtravessar();
    }

    public void enterRight() {
        obterPermissaoParaAtravessar();
    }

    public void leaveLeft() {
        liberarPermissao();
    }

    public void leaveRight() {
        liberarPermissao();
    }

    private void obterPermissaoParaAtravessar() {
        try {
            sem.acquire();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
    
    private void liberarPermissao() {
        sem.release();
    }

}