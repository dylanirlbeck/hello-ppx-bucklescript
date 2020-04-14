# hello-ppx-bucklescript

A project that includes the minimum configuration for a ppx called `hello`, using Reason and BuckleScript. Inspired by [hello-ppx-esy](https://github.com/jchavarri/hello-ppx-esy/).

`hello-ppx-bucklescript` implements a very basic ppx that transforms the `[%hello]` extension into the number literal `42`.
So, the code:

```reason
let fourtyTwo = string_of_int([%hello])
```

is transformed into:

```reason
let fourtyTwo = string_of_int(42)
```

at compile time.

## Project structure

`src/` - contains the source code for the ppx. Check out [this blog post](https://blog.hackages.io/reasonml-ppx-8ecd663d5640) for more information on the implementation of `[%hello]`.

`tests/` - contains a single file, `Tests.re`, that prints out the value of the `[%hello]` ppx. You can verify that the output is correct by running `yarn test`.

`publish/` - the folder you publish to NPM which contains the ppx executable.

## Publishing your ppx

It's likely you'll want to share your ppx with the Reason community. That's great! The `publish/` directory contains boilerplate for publishing your project (ppx) to the NPM registry so that others can install it by doing

`npm i hello_ppx`

and adding the ppx flag to their bsconfig.json

`"ppx-flags": ["hello-ppx-bucklescript/ppx"]`

As the documentation of bsconfig.json says, ppx flags are specified by package_name/binary, which allows BuckleScript to find each ppx in in your node_modules (this also explains why we `npm i` each ppx). Thus, the most important part of this process is the generated binary for the ppx that is consumed by other developers. In our case, this binary is located at `publish/ppx`.

If you've never published on NPM before, I'd highly recommend checking out [this tutorial](https://eladnava.com/publishing-your-first-package-to-npm/).

    "postinstall": "bsb -make-world -backend js; cp lib/bs/js/hello.native ./ppx",