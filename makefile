build:
	bazel build src/...

clean:
	bazel clean

rebuild: clean build

test-all:
	bazel test test/...

run:
	bazel run //src:server -- --port 1234
