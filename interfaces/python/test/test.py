from __future__ import print_function
import sys
import os

sys.path.append('.')
sys.path.append('./..')

tests = []


SkipTests = False
try:
    import sys
    script_path = os.path.dirname(os.path.abspath(__file__))
    sys.path.append(os.path.join(script_path, '../../../tools/utilities/pythonlibs'))
    import find_ell
    import ell
    import functions_test
    import model_test
    import modelbuilder_test
    import common_test
    import trainers_test
    import predictors_test
    import nodes_test
    import linear_test
    import evaluators_test
    import protonn_trainer_test
    import dataset_test
    import vector_test
    import compiled_model_test

    tests = [
        (functions_test.test,       "functions_test"),
        (dataset_test.test,         "dataset_test"),
        (vector_test.test,          "vector_test"),
        (model_test.test,           "model_test"),
        (common_test.test,          "common_test"),
        (trainers_test.test,        "trainers_test"),
        (predictors_test.test,      "predictors_test"),
        (nodes_test.test,           "nodes_test"),
        (linear_test.test,          "linear_test"),
        (evaluators_test.test,      "evaluators_test"),
        (modelbuilder_test.test,    "modelbuilder_test"),
        (protonn_trainer_test.test, "protonn_trainer_test"),
        (compiled_model_test.test,  "compiled_model_test"), # must come after protonn_trainer_test because it depends on the model generated by that test.
    ]
except ImportError as err:
    if "Could not find ell package" in str(err):
        print("Python was not built, so skipping test")
        SkipTests = True
    else:
        raise err

def interface_test():
    rc = 0
    for (test, name) in tests:
        try:
            ans = test()
            if ans == 0:
                print(name, "passed")
            else:
                print(name, "failed")
            rc |= ans
        except Exception as e:
            print(name, "failed")
            print("exception:", e)
            rc = 1
    sys.exit(rc)

if not SkipTests:
    interface_test()

