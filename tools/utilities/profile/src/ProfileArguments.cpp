////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     ProfileArguments.cpp (profile)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ProfileArguments.h"

namespace ell
{
void ParsedProfileArguments::AddArgs(utilities::CommandLineParser& parser)
{
    parser.AddOption(
        inputTestFile,
        "testFile",
        "tf",
        "Path to the test data (an image file)",
        "");

    parser.AddOption(
        outputFilename,
        "outputFilename",
        "of",
        "File for profiling output ('<cout>' for stdout, blank or '<null>' for no output)",
        "<cout>",
        "-");

    parser.AddOption(
        timingOutputFilename,
        "timingOutput",
        "",
        "File for node timing detail output ('<cout>' for stdout, blank or '<null>' for no output)",
        "",
        "<cout>");

    parser.AddOption(
        outputFormat,
        "format",
        "fmt",
        "Format for profiling output ('text' or 'json')",
        { { "text", ProfileOutputFormat::text }, { "json", ProfileOutputFormat::json } },
        "text");

    parser.AddOption(
        outputComment,
        "comment",
        "",
        "Comment to embed in output",
        "",
        "");

    parser.AddOption(
        filterTrivialNodes,
        "filter",
        "",
        "Filter trivial nodes (InputNode and ConstantNode) from note type output",
        true);

    parser.AddOption(
        numIterations,
        "numIterations",
        "n",
        "Number of times to run model during the profiling phase",
        1);

    parser.AddOption(
        numBurnInIterations,
        "burnIn",
        "",
        "Number of initial iterations to run before starting the profiling phase",
        0);

    parser.AddOption(
        summaryOnly,
        "summary",
        "",
        "Print timing summary only",
        false);

    parser.AddOption(
        optimize,
        "optimize",
        "",
        "Optimize compiled code",
        true);

    parser.AddOption(
        useBlas,
        "blas",
        "",
        "Use BLAS libraries in compiled code",
        true);

    parser.AddOption(
        fuseLinearOperations,
        "fuseLinearOps",
        "",
        "Fuse sequences of linear operations with constant coefficients into a single operation",
        true);

    parser.AddOption(
        enableVectorization,
        "vectorize",
        "vec",
        "Enable ELL's vectorization",
        false);

    parser.AddOption(
        vectorWidth,
        "vectorWidth",
        "vw",
        "Size of vector units",
        4);
}
}
