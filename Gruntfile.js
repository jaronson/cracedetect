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

  grunt.registerTask('build', [
    'shell:lint',
    'shell:make'
  ]);

  grunt.registerTask('default', [
    'build'
  ]);
};
