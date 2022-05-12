FUNÇÃO:
    procedimento1 (valor arg1Proc : inteiro) =
        local:
            localProc : inteiro := 2

        ação:
            imprimei(arg1Proc);
            arg1Proc := 250;
            imprimei(arg1Proc);
            imprimei(localProc);
            localProc := funcao1(10, 20);
            imprimei(localProc)

    funcao1 (valor arg1Fun: inteiro, valor arg2Fun : inteiro) : inteiro =
        ação:
            imprimei(123456789);
            retorne arg2Fun

AçÃo:
    procedimento1(5);
    retorne 0

