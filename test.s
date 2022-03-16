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