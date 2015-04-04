module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-shell');

  grunt.initConfig({
    shell: {
      options: {
        execOptions: {
          maxBuffer: Infinity
        }
      },
      lint: {
        command: 'cpplint src/*'
      },

      makeAll: {
        command: 'make -j4'
      },

      makeTests: {
        command: 'make -j4 tests'
      },

      test: {
        command: 'for t in build/*unittest; do $t; done'
      }
    },

    clean: ['build/*', 'bin/*'],

    watch: {
      options: {
        atBegin: true
      },
      src: {
        files: ['src/*', 'include/*', 'test/*'],
        tasks: ['build']
      }
    }
  });

  grunt.registerTask('lint', [
    'shell:lint'
  ]);

  grunt.registerTask('cmake', [
    
  ]);

  grunt.registerTask('make', [
  ]);

  grunt.registerTask('all', [
    'clean',
    'cmake'
    'make'
  ]);

  grunt.registerTask('default', [
    'all'
  ]);
};
