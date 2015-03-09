module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-bg-shell');

  grunt.initConfig({
    bgShell: {
      _defaults: {
        bg: false,
        execOpts: {
          maxBuffer: false
        }
      },

      make: {
        cmd: 'make -j 4'
      },
    },

    clean: ['build/*', 'bin/*'],

    watch: {
      src: {
        files: [
          'src/*', 'include/*'
        ],
        tasks: ['make']
      }
    }
  });

  grunt.registerTask('build', [
    'bgShell:make'
  ]);

  grunt.registerTask('default', []);
};
