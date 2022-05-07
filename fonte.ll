; ModuleID = 'my cool jit'
source_filename = "my cool jit"

declare i32 @imprimei(double)

define i32 @funcao2() {
entry:
  %calltmp = call i32 @funcao(i32 3, i32 4)
  ret i32 %calltmp
}

define i32 @funcao(i32 %arg3, i32 %arg4) {
entry:
  %a = alloca i32, align 4
  %arg42 = alloca i32, align 4
  %arg31 = alloca i32, align 4
  store i32 %arg3, i32* %arg31, align 4
  store i32 %arg4, i32* %arg42, align 4
  %arg33 = load i32, i32* %arg31, align 4
  store i32 %arg33, i32* %a, align 4
  %a4 = load i32, i32* %a, align 4
  %calltmp = call i32 @imprimei(i32 %a4)
  store i32 14, <null operand!>, align 4
  %a5 = load i32, i32* %a, align 4
  %calltmp6 = call i32 @imprimei(i32 %a5)
  ret i32 %calltmp6
}

define i32 @main() {
entry:
  %calltmp = call i32 @funcao2()
  ret i32 %calltmp
}
