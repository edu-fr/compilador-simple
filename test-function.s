tipo: 
    tipoNovo = tipoAntigo
    tipoVelho = newerType
    tipoRegistro = { regCampo1: tipoNovo, regCampo2: tipoVelho }

global: 
    varglob: tipoNovo := NULO 

funÇão: 
    fiuncao (rEf param1: tipoVelho, vaLor paRam2: inteIRO ) : tipoVelho = 
        local:  
            novaLocal: tipoNovo := 1==2==3 
            novaNovaLocal: tipoVelho := 1|(2>2)>2&(var1.a2+(25* var1.campo1))
            localRegistro: tipoRegistro := { regCampo1 = 1 , regCampo2 = 10}
        ação: 
            ident := nulo;
            ident2 := nulo

    fiuncao2 () : tipoNovo =
        ação: 
            ident := nulo;
            ident2 := nulo

    proced() = 
        ação:
            ident1 := 1

-------------------------

tipo:
    a = inteiro
    b = a
    tipoRegistro = { d : cadeia, e : real }
    tipoRegistro = {d:cadeia}
    f = [ 2, 3 ] de b
    f = [2,3] de b

global:
    identificador : inteiro := 10.5
    identificador : real := 10.5 + a - 2
    identificador : inteiro := (10 | 2) & 8
    /*identificador : inteiro := a == b == c /*isso tem que dar erro */
    exprRelacional : inteiro := a != (b == c)
    chamadaFc : inteiro := funcao()
    chamadaFc : inteiro := funcao(param1, 2, param2)
    chamadaFc : inteiro := (funcao())
    registro : tipoRegistro := { d = "cadeia", e = 10.5 }
    