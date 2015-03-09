module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-shell');

  grunt.initConfig({
    shell: {
      lint: {
        command: 'cpplint include/* src/*'
      },

      make: {
        command: 'make -j4'
      }
    },

    clean: ['build/*', 'bin/*'],

    watch: {
      options: {
        atBegin: true
      },
      src: {
        files: ['src/*', 'include/*'],
        tasks: ['build']
      }
    }
  });

  grunt.registerTask('lint', [
    'shell:lint'
  ]);

  grunt.registerTask('make', [
    'shell:make'
  ]);

  grunt.registerTask('all', [
    'lint',
    'make'
  ]);

  grunt.registerTask('default', [
    'build'
  ]);
};
