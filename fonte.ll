; ModuleID = 'my cool jit'
source_filename = "my cool jit"

declare void @imprimei(i32)

define void @procedimento1(i32 %arg1Proc) {
entry:
  %localProc = alloca i32, align 4
  %arg1Proc1 = alloca i32, align 4
  store i32 %arg1Proc, i32* %arg1Proc1, align 4
  store i32 2, i32* %localProc, align 4
  %arg1Proc2 = load i32, i32* %arg1Proc1, align 4
  call void @imprimei(i32 %arg1Proc2)
  store i32 250, i32* %arg1Proc1, align 4
  %arg1Proc3 = load i32, i32* %arg1Proc1, align 4
  call void @imprimei(i32 %arg1Proc3)
  %localProc4 = load i32, i32* %localProc, align 4
  call void @imprimei(i32 %localProc4)
  %calltmp = call i32 @funcao1(i32 10, i32 20)
  store i32 %calltmp, i32* %localProc, align 4
  %localProc5 = load i32, i32* %localProc, align 4
  call void @imprimei(i32 %localProc5)
  ret void
}

define i32 @funcao1(i32 %arg1Fun, i32 %arg2Fun) {
entry:
  %arg2Fun2 = alloca i32, align 4
  %arg1Fun1 = alloca i32, align 4
  store i32 %arg1Fun, i32* %arg1Fun1, align 4
  store i32 %arg2Fun, i32* %arg2Fun2, align 4
  call void @imprimei(i32 123456789)
  %arg2Fun3 = load i32, i32* %arg2Fun2, align 4
  ret i32 %arg2Fun3
}

define i32 @main() {
entry:
  call void @procedimento1(i32 5)
  ret i32 0
}
