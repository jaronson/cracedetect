require 'watchr'

script = Watchr::Script.new

script.watch('(src|include)/*') do
  system 'make clean && make -j 4'
end

controller = Watchr::Controller.new(script, Watchr.handler.new)
controller.run
