module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-shell');

  grunt.initConfig({
    shell: {
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

  grunt.registerTask('make', [
    'shell:makeAll',
    'shell:makeTests'
  ]);

  grunt.registerTask('test', [
    'shell:test'
  ]);

  grunt.registerTask('build', [
    'lint',
    'make',
    'test'
  ]);

  grunt.registerTask('all', [
    'clean',
    'lint',
    'make',
    'test'
  ]);

  grunt.registerTask('default', [
    'all'
  ]);
};
