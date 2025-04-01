using System.Net;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Azure.Functions.Worker.Http;
using Microsoft.Extensions.Logging;

namespace AzureProject
{
    public class HttpExample
    {
        private readonly ILogger _logger;

        public HttpExample(ILoggerFactory loggerFactory)
        {
            _logger = loggerFactory.CreateLogger<HttpExample>();
        }

        [Function("Function1")]
        public HttpResponseData Run([HttpTrigger(AuthorizationLevel.Anonymous, "get", "post")] HttpRequestData req)
        {
            _logger.LogInformation("C# HTTP trigger function processed a request.");

            var response = req.CreateResponse(HttpStatusCode.OK);
            response.Headers.Add("Content-Type", "text/plain; charset=utf-8");

            response.WriteString("Hello, Functions. This HTTP triggered function executed successfully. (Kyle W)");

            return response;
        }
    }
}
