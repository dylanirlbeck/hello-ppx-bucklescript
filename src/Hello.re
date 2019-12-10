open Ast_mapper;
open Parsetree;

let expr = (mapper, e) =>
  switch (e.pexp_desc) {
  /* If the expression is [%hello] */
  | Pexp_extension(({txt: "hello", loc, _}, _payload)) =>
    /* Then replace by 42 */
    Ast_helper.Exp.constant(Asttypes.Const_int(42))
  | _ => Ast_mapper.default_mapper.expr(mapper, e)
  };

let mapper = _ => {...Ast_mapper.default_mapper, expr};

let () = Ast_mapper.run_main(mapper);
