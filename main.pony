use "lib:threader"
use "path:build/"

actor Main
  new create(env: Env) =>
    @printf[None]("A - 🐺\n".cpointer())
    @register_callback[None](addressof fn)
    @printf[None]("B - 🦊\n".cpointer())
    @create_thread[None]()
    @printf[None]("C - 🐱\n".cpointer())

  fun @fn() =>
    @printf[None]("D - 🐶\n".cpointer())
    let ball = Ball

    @printf[None]("E - 🐎\n".cpointer())
    ball.inc()

    @printf[None]("F - 🐛\n".cpointer())

actor Ball
  var bounces: U32
  new create() =>
    @printf[None]("D' - 🦁\n".cpointer())
    bounces = 0

  be inc() =>
    @printf[None]("E' - 🐅\n".cpointer())
    bounces = bounces + 1
