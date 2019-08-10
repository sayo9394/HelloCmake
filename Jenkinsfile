String cron_string = BRANCH_NAME == "master" ? "H/15 * * * *" : ""

pipeline {
    agent any

    environment {
        PATH="/opt/qt510/bin:$HOME/bin:/usr/local/bin:$PATH"
        LD_LIBRARY_PATH="/opt/qt510/lib:$LD_LIBRARY_PATH"
    }

    triggers { pollSCM(cron_string) }

    stages {
        stage('Clean') {
            steps {
                sh "make clean"
            }
        }
        stage('CloneDeps') {
            steps {
                sh "make clone-deps"
            }
        }
        stage('Build') {
            steps {
                sh "make build-service -j8"
            }
        }
        stage('Install') {
            steps {
                sh "sudo make install-service -j8"
            }
        }
        stage('UnitTest') {
            steps {
                sh "make run-unittest -j8"
            }
        }
        stage('Valgrind') {
            steps {
                sh "make generate-valgrind-suppressions -j8"
                runValgrind (
                    childSilentAfterFork: true,
                    excludePattern: '',
                    generateSuppressions: true,
                    ignoreExitCode: true,
                    includePattern: 'build/unittest/bin/*_UnitTest',
                    outputDirectory: '',
                    outputFileEnding: '.memcheck',
                    programOptions: '',
                    removeOldReports: true,
                    suppressionFiles: 'min.supp',
                    tool: [$class: 'ValgrindToolMemcheck',
                        leakCheckLevel: 'full',
                        showReachable: true,
                        trackOrigins: true,
                        undefinedValueErrors: true],
                    traceChildren: true,
                    valgrindExecutable: '',
                    valgrindOptions: '',
                    workingDirectory: 'build/unittest/bin/'
                )
                publishValgrind (
                    failBuildOnInvalidReports: false,
                    failBuildOnMissingReports: false,
                    failThresholdDefinitelyLost: '',
                    failThresholdInvalidReadWrite: '',
                    failThresholdTotal: '',
                    pattern: '*.memcheck',
                    publishResultsForAbortedBuilds: false,
                    publishResultsForFailedBuilds: false,
                    sourceSubstitutionPaths: '',
                    unstableThresholdDefinitelyLost: '',
                    unstableThresholdInvalidReadWrite: '',
                    unstableThresholdTotal: ''
                )
            }
        }
        stage('Cleanup') {
            steps {
                cleanWs(cleanWhenAborted: true, cleanWhenFailure: true, cleanWhenNotBuilt: true, cleanWhenSuccess: true, cleanWhenUnstable: true, deleteDirs: true)
            }
        }
    }
    post {
        always {
            echo 'Workspace Cleanup'
            deleteDir() /* clean up our workspace */
        }
        failure {
            // send to email
            emailext (
                subject: "FAILURE: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]'",
                body: """<p>FAILURE: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]':</p>
                    <p>Check console output at "<a href="${env.BUILD_URL}">${env.JOB_NAME} [${env.BUILD_NUMBER}]</a>"</p>""",
                recipientProviders: [
                    [$class: 'DevelopersRecipientProvider'],
                    [$class: 'RequesterRecipientProvider'],
                    [$class: 'CulpritsRecipientProvider']
                ]
            )
        }
        changed {
            // send to email
            emailext (
                subject: "CHANGED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]'",
                body: """<p>CHANGED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]':</p>
                    <p>Check console output at "<a href="${env.BUILD_URL}">${env.JOB_NAME} [${env.BUILD_NUMBER}]</a>"</p>""",
                recipientProviders: [
                    [$class: 'DevelopersRecipientProvider'],
                    [$class: 'RequesterRecipientProvider'],
                    [$class: 'CulpritsRecipientProvider']
                ]
            )
        }
    }
}