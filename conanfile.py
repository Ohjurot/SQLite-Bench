from conan import ConanFile

class MoxPPRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "PremakeDeps"

    def requirements(self):
        self.requires("benchmark/1.8.3")
        self.requires("sqlite3/3.43.1")
