; ModuleID = 'my cool jit'
source_filename = "my cool jit"

declare void @imprimei(i32)

define i32 @FUNCAO(i32 %arg45, i32 %arg46) {
entry:
  %arg462 = alloca i32, align 4
  %arg451 = alloca i32, align 4
  store i32 %arg45, i32* %arg451, align 4
  store i32 %arg46, i32* %arg462, align 4
  call void @imprimei(i32 25)
  %arg453 = load i32, i32* %arg451, align 4
  %calltmp = call i32 @funcao5(i32 %arg453)
  ret i32 %calltmp
}

define i32 @funcao5(i32 %argFuncao5) {
entry:
  %a = alloca i32, align 4
  %argFuncao51 = alloca i32, align 4
  store i32 %argFuncao5, i32* %argFuncao51, align 4
  store i32 2, i32* %a, align 4
  %argFuncao52 = load i32, i32* %argFuncao51, align 4
  call void @imprimei(i32 %argFuncao52)
  store i32 250, i32* %argFuncao51, align 4
  %argFuncao53 = load i32, i32* %argFuncao51, align 4
  call void @imprimei(i32 %argFuncao53)
  %argFuncao54 = load i32, i32* %argFuncao51, align 4
  ret i32 %argFuncao54
}

define i32 @main() {
entry:
  call void @imprimei(i32 10)
  %calltmp = call i32 @FUNCAO(i32 10, i32 20)
  call void @imprimei(i32 %calltmp)
  ret i32 0
}
